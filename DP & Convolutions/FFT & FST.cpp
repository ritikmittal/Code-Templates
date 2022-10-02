typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
int n = sz(a), L = 31 - __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1);
for (static int k = 2; k < n; k *= 2) {
    R.resize(n); rt.resize(n);
    auto x = polar(1.0L, acos(-1.0L) / k);
    for(ll i=k;i<2*k;i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}vll rev(n);
for(ll i=0;i<n;i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
for(ll i=0;i<n;i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) for(ll j=0;j<k;j++) {
    // C z = rt[j+k] * a[i+j+k];(can replace next 2 lines)
    auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
    C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
    a[i + j + k] = a[i + j] - z;a[i + j] += z;}}
vd conv(const vd& a, const vd& b) {
if (a.empty() || b.empty()) return {};
vd res(sz(a) + sz(b) - 1);
int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
vector<C> in(n), out(n);copy(all(a), begin(in));
for(ll i=0;i<sz(b);i++) in[i].imag(b[i]);fft(in);
for (C& x : in) x *= x;
for(ll i=0;i<n;i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
fft(out);
for(ll i=0;i<sz(res);i++) res[i] = imag(out[i]) / (4 * n);
return res;}//FST from here
void FST(vll& a, bool inv) {
    for (ll n = sz(a), step = 1; step < n; step *= 2) {
        for (ll i = 0; i < n; i += 2 * step) for(ll j=i;j<i+step;j++) {
            ll &u = a[j], &v = a[j + step]; 
            tie(u, v) =inv ? pll(v - u, u) : pll(v, u + v);}} // AND
            // inv ? pll(v, u - v) : pll(u + v, u); // OR 
            // pll(u + v, u - v);                   // XOR 
    // if (inv) for (ll& x : a) x /= sz(a); // XOR only
}
vll conv(vll a, vll b) {
FST(a, 0); FST(b, 0);
for(ll i=0;i<sz(a);i++) a[i] *= b[i];
FST(a, 1); return a;}