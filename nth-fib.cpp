map<int,int>F;
int f(int n){
    if(F.count(n)) return F[n];
    if(n==0 || n==1) return 1;
    int k=n/2;
    if(n%2==0) return F[n]=(f(k)*f(k)+f(k-1)*f(k-1))%mod;
    else return F[n]=(f(k)*f(k+1)+f(k-1)*f(k))%mod;
}
