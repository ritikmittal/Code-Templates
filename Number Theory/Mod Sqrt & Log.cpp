// root(a) in mod P ,generally log(p) , worst log^2(p)
ll modSqrt(ll a, ll p) {
    a %= p; if (a < 0) a += p;
    if (a == 0) return 0;
    if(power(a, (p-1)/2, p) != 1){
        return -1;
    } // no solution
    if (p % 4 == 3) return power(a, (p+1)/4, p);
    // a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5
    ll s = p - 1, n = 2;
    int r = 0, m;
    while (s % 2 == 0)
        ++r, s /= 2;
    /// find a non-square mod p
    while (power(n, (p - 1) / 2, p) != p - 1) ++n;
    ll x = power(a, (s + 1) / 2, p);
    ll b = power(a, s, p), g = power(n, s, p);
    for (;; r = m) {
        ll t = b;
        for (m = 0; m < r && t != 1; ++m)
            t = t * t % p;
        if (m == 0) return x;
        ll gs = power(g, 1LL << (r - m - 1), p);
        g = gs * gs % p;
        x = x * gs % p;
        b = b * g % p;
    }
}
//(MOD2,MOD,modSqrt(MOD2,MOD)): 998244353 1000000007 108186848

//O(root(m))
int modLog(int a, int b, int m) {
    int n = (int) sqrtl(m) + 1, e = 1, f = 1, j = 1;
    unordered_map<int, int> A;
    while (j <= n && (e = f = e * a % m) != b % m)
        A[e * b % m] = j++;
    if (e == b % m) return j;
    if (__gcd(m, e) == __gcd(m, b))
        for(int i=2;i<n+2;i++) if (A.count(e = e * f % m))
                return n * i - A[e];
    return -1;
}
// (modLog(2,15,29)): 27
// (modLog(3,15,29)): 11