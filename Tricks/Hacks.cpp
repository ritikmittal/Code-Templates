mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll val=rng();vll v;shuffle(all(v),rng);
ll rand(ll x,ll y){return uniform_int_distribution<ll>(x,y)(rng);}

//* Find the smallest i in [a,b] that maximizes f(i), assuming that f(a) < f(i) <= f(b)$.
//* To reverse which of the sides allows non-strict inequalities, change the < marked with (A) to <=, and reverse the loop at (B).
//* To minimize f, change it to >, also at (B).
ll ternSearch(ll a, ll b) {
assert(a <= b);
while (b - a >= 5) {
    ll mid = (a + b) / 2;
    if (f(mid) < f(mid+1)) a = mid; // (A)
    else b = mid+1;}
for(ll i=a+1;i<(b+1),i++) if (f(a) < f(i)) a = i; // (B)
return a;
}

// checks if a*b will overflow
bool is(ll a,ll b){
if(a==0 || b==0) return false;
if((a>LLONG_MAX/b) or ( b>LLONG_MAX/a)) return true;
return false;
}
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);}
size_t operator()(pair<uint64_t,uint64_t> x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);}
size_t operator()(vector<ll> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    uint64_t v=sz(x);
    for(int i=0;i<sz(x);i++){
        v^=(splitmix64(x[i]+FIXED_RANDOM)>>(i%4));}
    return v;}};

std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
start = std::chrono::high_resolution_clock::now();
//code here
end = std::chrono::high_resolution_clock::now();
size_t elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
cout << "\nElapsed Time: " << elapsed_time << "ms\n";
// x= bit whose subsets we want
ll x=bit;ll ss=0;
do{}while(ss=(ss-x)&x);
//nth fib
if(n%2==0) return F[n]=(f(k)*f(k)+f(k-1)*f(k-1))%mod;
else return F[n]=(f(k)*f(k+1)+f(k-1)*f(k))%mod;

