const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
    ll n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static ll k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, power(root, mod >> s,mod)};
        for(ll i=k;i<2*k;i++) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vll rev(n);
    for(ll i=0;i<n;i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for(ll i=0;i<n;i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (ll k = 1; k < n; k *= 2)
        for (ll i = 0; i < n; i += 2 * k) for(ll j=0;j<k;j++) {
        ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? mod : 0);
        ai += (ai + z >= mod ? z - mod : z);
    }}
vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    ll s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    ll inv = power(n, mod - 2,mod);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    for(ll i=0;i<n;i++) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};}