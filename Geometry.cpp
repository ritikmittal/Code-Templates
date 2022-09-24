#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
#define pr             pair<int,int>
#define vi             vector<int>
#define vvi            vector<vi>
#define vpr            vector<pr>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NITIN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/*

*/
typedef ld T;
struct pt {
    T x, y;

    pt operator+(pt p) { return {x + p.x, y + p.y}; };

    pt &operator+=(const pt &t) {
        x += t.x;
        y += t.y;
        return *this;
    }

    pt operator-(pt p) { return {x - p.x, y - p.y}; }

    pt &operator-=(const pt &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }

    pt operator*(T d) { return {x * d, y * d}; }

    pt &operator*=(T t) {
        x *= t;
        y *= t;
        return *this;
    }

    //only for floating point
    pt operator/(T d) { return {x / d, y / d}; }

    pt &operator/=(T t) {
        x /= t;
        y /= t;
        return *this;
    }

    pt &operator=(pt b) {
        x = b.x;
        y = b.y;
        return *this;
    }

    bool operator<(const pt &a) const {
        if (a.x == x) {
            return y < a.y;
        } else {
            return x < a.x;
        }
    }

    bool operator>(const pt &a) const {
        if (a.x == x) {
            return y > a.y;
        } else {
            return x > a.x;
        }
    }
};
bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

// squared absolute value
T sq(pt p) {return p.x*p.x + p.y*p.y;}
ld abs(pt p) {return sqrt(sq(p));}

//print points
ostream& operator<<(ostream& os, pt p) {
    return os << "("<< p.x << "," << p.y << ")";
}

// signum function
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

// translate a point p by point v
pt translate(pt v,pt p) {return p+v;}

//scale vector p by factor around center c
pt scale(pt c,ld factor,pt p) {
    return c + (p - c) * factor;
}

//lattice points on segment (a,b)
int latticePoints(pt a,pt b) {
    return gcd((int)(abs(a.x - b.x)), (int)(abs(a.y - b.y))) - 1;
}

ld dtr(ld ang){
    return (ang*PI)/100;
}
ld rtd(ld ang){
    return (ang*180)/PI;
}

// rotate point p by angle a around center origin , counterclockwise
pt rot(pt p, ld a) {
    return {T(p.x*cos(a) - p.y*sin(a)), T(p.x*sin(a) + p.y*cos(a))};
}
// rotate point perpendicular though origin in counterclockwise
pt prep(pt p) {return {-p.y, p.x};}

// rotate vector p by angle a around vector c as center, counterclockwise
pt rot(pt c, pt b, ld a) {
    return c + rot(b - c, a);
}

// f(x)=a*x+b, if p is change to f(p) and q to f(q), to what r is changed
// a is real number and b is some vector
pt linearTransformation(pt p,pt q,pt r,pt fp,pt fq) {
    return fp + (r - p) * ((fq - fp).x / (q - p).x);
}

// dot product
T dot(pt a, pt b) {return a.x*b.x + a.y*b.y;}
// check if two vector are perpendicular
bool isPrep(pt a,pt b){ return dot(a,b)==0;}
// get the angle between two vectors
ld angle(pt a,pt b) {
    ld cosTheta = dot(a, b) / abs(a) / abs(b);
    cosTheta = min(cosTheta, ld(1.0));
    cosTheta = max(cosTheta, ld(-1.0));
    return acos(cosTheta);
}

// cross product
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
// if we move from b to c, around a
// returns negative if right turn
// returns positive if left turn
// returns zero if collinear
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
// angle made at a while we turn from b to c around a
// between [0,2*PI]
ld orientedAngle(pt a,pt b,pt c) {
    if (orient(a, b, c) >= 0)
        return angle(b - a, c - a);
    else
        return 2 * PI - angle(b - a, c - a);
}
// amplitude travelled around point A, from P to Q
// between [-PI,PI]
ld angleTravelled(pt a,pt p,pt q) {
    ld ampli = angle(p - a, q - a);
    if (orient(a, p, q) > 0) return ampli;
    return -ampli;
}
// returns if p lies inside the angle formed by a,b,c with a at center
bool isInAngle(pt a,pt b,pt c,pt p) {
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

//check if a polygon is convex
// all the orientation for vertex of a polygon should be of same sign
// vertices are given in order
bool isConvex(vector<pt>&p) {
    bool pos = false, neg = false;
    for (int i = 0, n = sz(p); i < n; i++) {
        int o = orient(p[(i + 1) % n], p[i], p[(i + 2) % n]);
        if (o > 0) pos = true;
        if (o < 0) neg = true;
    }
    return !(pos && neg);
}

// return if the point p is in the half region defined
// dividing the region into two half is necessary because in a*b is in right side
// if a*b>0 but only for PI angle so divide them sort them individually consider which
// half region you want up
bool half(pt p) {
    assert(p.x != 0 || p.y != 0); // (0,0) is not defined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

// sort in order of (-PI,PI]
void polarSort(vector<pt>&v) {
    sort(v.begin(), v.end(), [](pt a, pt b) {
        return make_tuple(half(a), 0) < make_tuple(half(b), cross(a, b));
    });
}

struct line {
    pt v;
    T c; // v is vector parallel to line and c constant from a*x+b*y=c;
    // so our equation of line is cross(v,xi+yj)=c

    line(pt v, T c) : v(v), c(c) {}

    // from equation ax+by=c
    line(T a, T b, T c) : v({b, -a}), c(c) {}

    // from point p and q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    // for T as int

    // return =0 if lie on line, >0 if on left side of line,
    // <0 if on right side of line
    T side(pt p) { return cross(v, p) - c; }

    // return distance of point p from line
    ld dist(pt p) { return abs(side(p)) / abs(v); }

    // return squared distance of point p from line
    ld sqDist(pt p) { return (side(p) * side(p)) / (double) sq(v); }

    // perpendicular line that passes through p
    // return as two points (p, q=p+prep(v))
    line perpThrough(pt p) { return {p, p + prep(v)}; }

    // return in direction of line which point comes first
    bool cmpProj(pt p, pt q) {
        return dot(v, p) < dot(v, q);
    }

    // return the translated line by vector t
    line translate(pt t) {
        return {v, c + cross(v, t)};
    }

    // for T as double

    line shiftLeft(ld dist) {
        return {v, T(c + dist * abs(v))};
    }

    // projection of pt p on the line
    pt proj(pt p) { return p - prep(v) * side(v) / sq(v); }

    // reflection of pt p in the line
    pt ref(pt p) { return p - prep(v) * 2 * side(v) / sq(v); }

};

// fine intersection point of line l1,l2
bool inter(line l1,line l2,pt &out){
    T d=cross(l1.v,l2.v);
    if(d==0) return false;
    out=(l2.v*l1.c-l1.v*l2.c)/d; // requires floating point
    return true;
}

line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 should not be parallel
    double sign = interior ? 1 : -1;
    return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
            T(l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign)};
}

// return if point p lie on the disk with a,b as diameter
bool inDisk(pt a,pt b,pt p) {
    return dot(a - p, b - p) <= 0;
}
// return if point p lie on segment [a,b]
bool onSegment(pt a,pt b,pt p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

// return if segment [a,b], [c,d] intersection properly
// if endpoints is intersection, it is not considered proper intersection
bool properInter(pt a,pt b,pt c,pt d,pt &out) {
    ld oa = orient(c, d, a);
    ld ob = orient(c, d, b);
    ld oc = orient(a, b, c);
    ld od = orient(a, b, d);
    if (oa * ob < 0 && oc * od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}
//To create sets of points
struct cmp {
    bool operator()(pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }
};
// find the intersection points of segments [a,b] and [c,d]
// there might be zero, one, two(segment) point of intersections
set<pt,cmp> inter(pt a, pt b,pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    set<pt, cmp> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return s;
}

// segment point distance
ld segPointDist(pt a,pt b,pt p) {
    if (a != b) {
        line l(a, b);
        // if p's projection is on segment [a,b]
        if (l.cmpProj(a, p) && l.cmpProj(p, b)) return l.dist(p);
    }
    // otherwise, distance to A or B
    return min(abs(p - a), abs(p - b));
}

ld segSegDist(pt a,pt b,pt c,pt d) {
    pt dummy;
    if (properInter(a, b, c, d, dummy)) return 0;
    // endpoints will be at shortest distance
    return min({
                       segPointDist(a, b, c),
                       segPointDist(a, b, d),
                       segPointDist(c, d, a),
                       segPointDist(c, d, b)
               });
}

ld areaTriangle(pt a,pt b,pt c) {
    return abs(cross(b - a, c - a)) / 2.0;
}

// assumes the points are in counterclockwise order
// if in clockwise order area is going to be negative
// for both concave and convex
ld areaPolygon(vector<pt>&p) {
    ld area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}
int areaPolygonTw(vector<pt>&p) {
    int area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area);
}

// point in order of convex polygon
// if area is greater than zero then points are in counterClockwise
// otherwise clockwise
bool counterClockwise(vector<pt>&p) {
    int area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return area > 0;
}

//true if P is at least as high as A
bool above(pt a,pt p) {
    return p.y >= a.y;
}
//check if [PQ] crosses ray from A(going right)
bool crossesRay(pt a,pt p,pt q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}
//check if a point lie inside polygon(can be convex or concave)
bool inPolygon(vector<pt>&v,pt a,bool strict=true) {
    int numCrossings = 0;
    for (int i = 0, n = v.size(); i < n; i++) {
        if (onSegment(v[i], v[(i + 1) % n], a)) {
            return !strict;
        }
        numCrossings += crossesRay(a, v[i], v[(i + 1) % n]);
    }
    return numCrossings&1;
}

// returns how many times we go anticlockwise around a, following
// polyline, (a should not lie on polyline)
// if point is outside polygon, winding number is zero
int windingNumberFloat(vector<pt> &p,pt a) {
    ld ampli = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        ampli += angleTravelled(a, p[i], p[(i + 1) % n]);
    }
    return round(ampli / (2 * PI));
}

struct ang {
    pt d;
    int t = 0; //turns
    // angle is atan2(d)+2*PI*t

    ang(pt _d, int _t = 0) {
        d = _d;
        t = _t;
    }

    friend bool operator<(ang a, ang b) {
        return make_tuple(a.t, half(a.d), 0) <
               make_tuple(b.t, half(b.d), cross(a.d, b.d));
    }

    ang t180() {
        return {d * (-1), t + half(d)};
    }

    ang t360() {
        return {d, t + 1};
    }

    ang moveTo(ang a, pt newD) {
        assert(!onSegment(a.d, newD, {0, 0}));
        ang b{newD, a.t};
        if (a.t180() < b) b.t--;
        if (b.t180() < a) b.t++;
        return b;
    }
};

//assumes point doesnt lie on polygon
int windingNumberInt(vector<pt>p,pt o) {
    for (auto &c: p) c -= o;
    ang g = ang(p.back());
    for (auto &d: p) {
        g = g.moveTo(g, d);
    }
    return g.t;
}

// finds the center of circle passing through points a,b,c
pt circumCenter(pt a,pt b,pt c) {
    b = b - a, c = c - a;
    assert(cross(b, c) != 0);
    return a + prep(b * sq(c) - c * sq(b)) / cross(b, c) / 2;
}
// returns number of intersection points of line l with circle
int circleLine(pt o,ld r,line l,pair<pt,pt>&out) {
    ld h2 = r * r - l.sqDist(o);
    if (h2 >= 0) {
        pt p = l.proj(o);
        pt h = l.v * sqrt(h2) / abs(l.v);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

int circleCircle(pt o1,ld r1,pt o2,ld r2,pair<pt,pt>&out) {
    pt d = o2 - o1;
    ld d2 = sq(d);
    if (d2 == 0) {
        assert(r1 != r2);
        return 0; //concentric circle;
    }
    ld pd = (d2 - r1 * r1 - r2 * r2) / 2.0;
    ld h2 = r1 * r1 - pd * pd / d2;
    if (h2 >= 0) {
        pt p = o1 + d * pd / d2;
        pt h = prep(d) * sqrt(h2) / sqrt(d2);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

//tangents to circle
int tangents(pt o1, double r1, pt o2, double r2, bool inner, vector<pair<pt,pt>> &out) {
    if (inner) r2 = -r2;
    pt d = o2 - o1;
    ld dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0) {
        assert(h2 != 0);
        return 0;
    }
    for (ld sign: {-1, 1}) {
        pt v = (d * dr + prep(d) * sqrt(h2) * sign) / d2;
        out.push_back({o1 + v * r1, o2 + v * r2});
    }
    return 1 + (h2 > 0);
}

// reorder by first element being left bottom point
void reorder(vector<pt>&a){
    int pos=0;
    for(int i=1;i<a.size();i++){
        if(a[i].x<a[pos].x || (a[i].x==a[pos].x && a[i].y<a[pos].y)){
            pos=i;
        }
    }
    rotate(a.begin(),a.begin()+pos,a.end());
}
//inputs points are sorted in counterclockwise order
vector<pt> minkowskiSum(vector<pt>a,vector<pt>b) {
    reorder(a);
    reorder(b);
    vector<pt> ans;
    int i = 0, j = 0;
    int n = sz(a), m = sz(b);
    int times = n + m;
    while (times--) {
        ans.push_back(a[i] + b[j]);
        if (cross(a[(i + 1) % n] - a[i], b[(j + 1) % m] - b[j]) >= 0) {
            i++;
            i %= n;
        } else {
            j++;
            j %= m;
        }
    }
    // remove redundant points
    vector<pt> r_ans;
    for (int l = 0; l < n + m; l++) {
        if (orient(ans[(l - 1 + n + m) % (n + m)], ans[l], ans[(l + 1) % (n + m)]) != 0) {
            r_ans.push_back(ans[l]);
        }
    }
    return r_ans;
}

// lattice points in a polygon, pick's theorem
pair<int,int> latticePoints(vector<pt>&p) {
    int area = areaPolygonTw(p);
    int bdryPoints = 0;
    int n = p.size();
    for (int i = 0; i < p.size(); i++) {
        bdryPoints += latticePoints(p[i], p[(i + 1) % n]);
    }
    bdryPoints += sz(p);
    return {(area - bdryPoints + 2) / 2, bdryPoints};
}

bool ok(pt &a,pt &b,pt &c,bool includeCollinear){
    int o = orient(a, b, c);
    return o > 0 || (includeCollinear && o == 0);
}

vector<pt> convexHullGC(vector<pt>a,bool includeCollinear=false) {
    if (a.size() <= 2) return a;
    int n = sz(a);
    for (int i = 1; i < n; i++) {
        if (a[i].y < a[0].y || (a[i].y == a[0].y && a[i].x < a[0].x)) {
            swap(a[0], a[i]);
        }
    }
    pt o = a[0];
    sort(a.begin() + 1, a.end(), [&o](pt a, pt b) {
        int val = orient(o, a, b);
        if (val == 0) {
            return sq(o - a) < sq(o - b);
        }
        return val > 0;
    });
    vector<pt> stk;
    stk.push_back(a[0]);
    stk.push_back(a[1]);
    for (int i = 2; i < n; i++) {
        while (stk.size() >= 2 && !ok(stk[sz(stk) - 2], stk[sz(stk) - 1], a[i], includeCollinear)) {
            stk.pop_back();
        }
        stk.push_back(a[i]);
    }
    if (includeCollinear) {
        for (int j = n - 2; j > 0; j--) {
            if (orient(a[0], a[j], a.back()) == 0) {
                stk.push_back(a[j]);
            }
        }
    }
    return stk;
}

// minimum euclid distance using line sweep
int minEuclidDistance(vector<pt>&v) {
    set<pair<int, int>> s;
    int dist = 8e18;
    sort(v.begin(), v.end());
    int j = 0;
    for (auto &c: v) {
        int d = ceil(sqrt(dist));
        while (!s.empty() && c.x - v[j].x >= d) {
            s.erase({v[j].y, v[j].x});
            j++;
        }
        auto it1 = s.lower_bound({c.y - d, c.x});
        auto it2 = s.upper_bound({c.y + d, c.x});
        while (it1 != it2) {
            dist = min((T) dist, (T) sq(c - pt{(T) it1->second, (T) it1->first}));
            ++it1;
        }
        s.insert({c.y, c.x});
    }
    return dist;
}

//// angle sweep
//int max_point_ic(vector<point>p,ld r){
//    int n=p.size();
//    int ans=1;
//    for(int i=0;i<n;i++){
//        vector<pair<ld,pair<bool,int>>>ang;
//        int cur=1;
//        for(int j=0;j<n;j++){
//            if(i!=j){
//                ld d=sqrt((ld)(dot(p[j]-p[i],p[j]-p[i])));
//                if(d>2*r) continue;
//                ld alpha1=atan((p[j]-p[i]).y/((ld)(p[j]-p[i]).x));
//                if((p[j]-p[i]).x<0) alpha1+=PI;
//                ld alpha2=acos(d/(2*r));
//                ld entry=(8*PI+alpha1-alpha2);
//                entry-=2*PI* floor(entry/(2*PI));
//                ld exit=(8*PI+alpha1+alpha2);
//                exit-=2*PI* floor(exit/(2*PI));
//                if(entry>exit) cur++;
//                ang.push_back({entry,{false,j}});
//                ang.push_back({exit,{true,j}});
//            }
//        }
//        sort(ang.begin(),ang.end());
//        ans=max(ans,cur);
//        for(auto &c:ang){
//            if(!c.second.first) cur++;
//            else cur--;
//            ans=max(ans,cur);
//        }
//    }
//    return ans;
//}



//// rotating calliper:- largest euclid distance, diameter of convex polygon
//// return a^2
//int diameter(vector<point>a){
//    a= convex_hull_gc(a);
//    int n=a.size();
//    int ptr_a=0;
//    int ptr_b=1;
//    while(cross(a[(ptr_a+1)%n]-a[ptr_a],a[(ptr_b+1)%n]-a[ptr_b])>0){
//        ptr_b++;
//        ptr_b%=n;
//    }
//    int ans=dot(a[ptr_b]-a[ptr_a],a[ptr_b]-a[ptr_a]);
//    int begin_a=ptr_a;
//    int begin_b=ptr_b;
//    do{
//        if(cross(a[(ptr_a+1)%n]-a[ptr_a],a[(ptr_b+1)%n]-a[ptr_b])>0){
//            ptr_b++;
//            ptr_b%=n;
//        }else{
//            ptr_a++;
//            ptr_a%=n;
//        }
//        ans=max(ans,dot(a[ptr_b]-a[ptr_a],a[ptr_b]-a[ptr_a]));
//    }while(begin_a!=ptr_a || begin_b!=ptr_b);
//    return ans;
//}

void solve(){

}

int32_t main() {
    nitin;
    solve();
}
