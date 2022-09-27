#define FOR(i,a,b) for(ll i=a;i<b;i++)
typedef array<double, 2> P;
template<class F> pair<double, P> hillClimb(P start, F f) {
    pair<double, P> cur(f(start), start);
    for (double jmp = 1e9; jmp > 1e-20; jmp /= 2) {
        FOR(j,0,100) FOR(dx,-1,2) FOR(dy,-1,2) {
            P p = cur.second;
            p[0] += dx*jmp;
            p[1] += dy*jmp;
            cur = min(cur, make_pair(f(p), p));
        }
    }
    return cur;}
//use it for unimodal functions, change jmp value depending on the range of the function F
// hillClimb(point, &F) 