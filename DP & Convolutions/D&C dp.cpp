ll n;
// kth level , find for [l,r], optimal break lies btw [optl,optr]
void f(ll k,ll l, ll r, ll optl=1, ll optr=n){
if(r<l)return;ll mid= (l+r)/2;ll op=optl;
for(ll br=optl;br<=min(optr,mid -1);br++){
    ll nval=dp[br][k-1]+ Cost(br+1,mid);  
    if(nval<dp[mid][k]){
        dp[mid][k]=nval;op=br;}}
f(k,l,mid-1,optl,op);f(k,mid+1,r,op,optr);}