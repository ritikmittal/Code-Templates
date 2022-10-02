// root(a) in mod P ,generally log(p) , worst log^2(p)
ll modSqrt(ll a, ll p) {
 a %= p; if(a<0) a+=p;if(a==0)return 0;
 if(power(a,(p-1)/2,p) != 1){return -1;}
 if (p%4 == 3) return power(a,(p+1)/4,p);
 ll s = p - 1, n = 2;int r = 0, m;
while (s % 2 == 0)++r, s /= 2;
while (power(n, (p-1)/2,p) != p-1) ++n;
ll x = power(a, (s + 1) / 2, p);
ll b = power(a, s, p), g = power(n, s, p);
for (;; r = m) { ll t = b;
 for (m = 0; m < r && t != 1; ++m)t=t*t%p;
    if (m == 0) return x;
    ll gs = power(g, 1LL << (r - m - 1),p);
g=gs*gs%p;x = x * gs % p;b = b * g % p;}}
//(MOD2,MOD,modSqrt(MOD2,MOD)): 998244353
// 1000000007 108186848 ; O(root(m))
int modLog(int a, int b, int m) {
 int n = (int)sqrtl(m)+1,e=1,f=1,j=1;
 unordered_map<int, int> A;
 while(j<=n && (e=f=e*a%m)!=b%m)
    A[e * b % m] = j++;
 if (e == b % m) return j;
 if (__gcd(m, e) == __gcd(m, b))
 for(int i=2;i<n+2;i++) 
 if (A.count(e=e*f%m)) return n*i-A[e];
    return -1; }
//(modLog(2,15,29)):27;(modLog(3,15,29)):11
ull sumsq(ull to) {return to/2*((to-1)|1);}
ull divsum(ull to, ull c, ull k, ull m) {
ull res = k / m * sumsq(to) + c / m * to;
k %= m; c %= m; if (!k) return res;
ull to2 = (to * k + c) / m;
return res+(to-1)*to2-divsum(to2,m-1-c,m,k)
} ll modsum(ull to, ll c, ll k, ll m) {
c=((c%m)+m) % m; k = ((k % m) + m) % m;
return to*c+k*sumsq(to)-m*divsum(to,c,k,m)}