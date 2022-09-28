#include <bits/stdc++.h>
#define int long long
#define ll long long
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define inf            1e18
#define all(x)         x.begin(), x.end()
#define sz(x)          (int)(x).size()
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define fastIO         ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef ICPC
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define endl           "\n"
#define dbg(...)
#endif
int power(int x, int y, int p) {
    int res = 1; x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res;
}
