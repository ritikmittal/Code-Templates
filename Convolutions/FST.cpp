void FST(vll& a, bool inv) {
    for (ll n = sz(a), step = 1; step < n; step *= 2) {
        for (ll i = 0; i < n; i += 2 * step) for(ll j=i;j<i+step;j++) {
            ll &u = a[j], &v = a[j + step]; tie(u, v) =
                                                     inv ? pll(v - u, u) : pll(v, u + v); // AND
            // inv ? pll(v, u - v) : pll(u + v, u); // OR /// include-line
            // pll(u + v, u - v);                   // XOR /// include-line
        }
    }
    // if (inv) for (ll& x : a) x /= sz(a); // XOR only /// include-line
}
vll conv(vll a, vll b) {
    FST(a, 0); FST(b, 0);
    for(ll i=0;i<sz(a);i++) a[i] *= b[i];
    FST(a, 1); return a;
}