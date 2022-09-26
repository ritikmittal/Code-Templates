
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;}
//Time: 7 times the complexity of $a^b \mod c$.
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;}
ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

//Time: $O(n^{1/4})$, less for numbers with small factors.
vector<ull> prime_factors(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = prime_factors(x), r = prime_factors(n / x);
    l.insert(l.end(), all(r));
    return l;
}
vector<ull> factors;unordered_map<ll,ll> freq;
vector<pair<ull,ull>> v;
ull l,r,x,y;

void dfs_fact(ll ind,ull tillnow)
{
    if(ind==(ll)v.size())
    {
        factors.push_back(tillnow);
        return;
    }
    ull cur=1;
    fori(v[ind].second+1)
    {
        dfs_fact(ind+1,cur*tillnow);
        cur*=v[ind].first;
    }

}
void get_factors(ull n)
{
    vector<ull> temp=prime_factors(n);freq.clear();factors.clear();
    for(auto x:temp)
        if(freq.count(x))freq[x]++;
        else freq[x]=1;
    
    v.resize((ll)freq.size());
    copy(freq.begin(),freq.end(),v.begin());
    dfs_fact(0,1);
}
// prime_factors(2142000014994) = {2, 3, 7, 3, 17, 1000000007}
// some large primes are 1045057753,1028492617,1018363057