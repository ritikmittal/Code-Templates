const ll MOD=1e9+7; 
const ll N=1000005;
//if  MOD is small, use LUCAS theorem, make N= MOD
ll fact[N], invfact[N];
//define pow() & modinv() here
void precompute()
{
    fact[0]=fact[1]=1;
    for(ll i=2;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
    invfact[N-1]=modinv(fact[N-1]);
    for(ll i=N-2;i>=0;i--)invfact[i]=(invfact[i+1]*(i+1))%MOD;}
//with Lucas
ll nCr(ll n, ll r)
{
    if(r>n)
        return 0LL;
    if(n>=MOD){
        return nCr(n / MOD, r / MOD) * nCr(n % MOD, r % MOD)
    }
    ll num=fact[n];num*=invfact[r];num%=MOD;
    num*=invfact[n-r];num%=MOD;
    return num;
}
