if(n%2==0) return F[n]=(f(k)*f(k)+f(k-1)*f(k-1))%mod;
else return F[n]=(f(k)*f(k+1)+f(k-1)*f(k))%mod;