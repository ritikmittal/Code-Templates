// LUCAS :return nCr(n / MOD, r / MOD) * nCr(n % MOD, r % MOD)
const int MAXN=2e5 +25;
vector <int> prime;bool is_composite[MAXN];
int phi[MAXN],mu[MAXN],spf[MAXN],cnt[MAXN];
// if there is some other random multiplicative function,
// find f[p] , f[i*p]=f[i]*f[p](if p does not divide i) ,
// f[i*p]=f[i/ p**cnt[i]]*f[p**(cnt[i]+1](if p divides i)
void sieve (int n) {
    std::fill (is_composite, is_composite + n, false);
    phi[1] = 1;mu[1]=1;spf[1]=1;cnt[1]=0;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            prime.push_back (i);phi[i] = i - 1;mu[i]=-1;
            spf[i]=i;cnt[i]=1;}
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;spf[i*prime[j]]=prime[j];
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
                mu[i * prime[j]] = 0;cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
                mu[i * prime[j]] = mu[i] * mu[prime[j]];cnt[i * prime[j]] = 1;}}}}