using T = ll; // a/b rounded down
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }

bool _Q = 0;
struct Line {
    T a, b; mutable T lst;
    /// friend str ts(const Line& L) { return ts(vl{L.a,L.b,L.lst}); }
    T eval(T x) const { return a*x+b; }
    bool operator<(const Line&o)const{return _Q?lst<o.lst:a<o.a;}
    T last_gre(const Line& o) const { assert(a <= o.a);
        // greatest x s.t. a*x+b >= o.a*x+o.b
        return lst=(a==o.a?(b>=o.b?INF:-INF):fdiv(b-o.b,o.a-a));}
};

struct LineContainer: multiset<Line> {
    bool isect(iterator it) { auto n_it = next(it);
        if (n_it == end()) return it->lst = INF, 0;
        return it->last_gre(*n_it) >= n_it->lst; }
    void add(T a, T b) { // remove lines after
        auto it = insert({a,b,0}); while (isect(it)) erase(next(it));
        if (it == begin()) return;
        if (isect(--it)) erase(next(it)), isect(it);
        while (it != begin()) { // remove lines before
            --it; if (it->lst < next(it)->lst) break;
            erase(next(it)); isect(it); }
    }
    T qmax(T x) { assert(!empty());
        _Q = 1; T res = lower_bound({0,0,x})->eval(x); _Q = 0;
        return res; }
};

struct LCdeque : deque<Line> {
    void addBack(Line L) { // assume nonempty
        while (1) {
            auto a = back(); pop_back(); a.lst = a.last_gre(L);
            if (size() && back().lst >= a.lst) continue;
            push_back(a); break;
        }
        L.lst = INF; push_back(L);
    }
    void addFront(Line L) {
        while (1) {
            if (!size()) { L.lst = INF; break; }
            if (((L.lst = L.last_gre(front()))) >= front().lst) pop_front();
            else break;
        }
        push_front(L);
    }
    void add(T a, T b) { // line goes to one end of deque
        if (!size() || a <= front().a) addFront({a,b,0});
        else assert(a >= back().a), addBack({a,b,0});
    }
    int ord = 1; // 1 = x's come in increasing order, -1 = decreasing order
    T query(T x) {
        if(size() == 0)return INF;
        assert(ord);
        if (ord == 1) {
            while (front().lst < x) pop_front();
            return front().eval(x);
        } else {
            while(size()>1&&prev(prev(end()))->lst>=x)pop_back();
            return back().eval(x);
        }
    }
};
//LCDeque() => set order of query , use add to add a line Amortized O(N)
//LineContainer() =>use add and qmax, uAmortized O(Nlog(N))