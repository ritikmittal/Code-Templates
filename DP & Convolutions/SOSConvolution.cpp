#define FOR(i,a,b) for(ll i=a;i<b;i++)
const int B = 20; // Every input vector must need to be of size 1<<B
//SOS fori(B)forj(mask) if(mask&(1<<i))dp[mask]+=dp[mask^(1<<i)]
vll subset_sum_convolution(vll f, vll g) {
    vvll fhat(B + 1, vll (1 << B, 0)),ghat(B + 1, vll (1 << B, 0));
    FOR(mask,0,1LL<<B) 
    fhat[setbits(mask)][mask] = f[mask];ghat[setbits(mask)][mask] = g[mask];
    for (int i = 0; i < B; i++) fhat[i]=SOSDP(fhat[i]);ghat[i]= SOSDP(ghat[i]);
    vvll h(B + 1, vll (1 << B, 0));
    FOR(mask,0,1LL<<B) FOR(i,0,B)FOR(j,0,i+1)
                h[i][mask] += 1LL * fhat[j][mask] * ghat[i - j][mask] ;
    for (int i = 0; i < B; i++) {h[i]=INVSOSDP(h[i]);}
    vll fog(1 << B, 0);
    FOR(mask,0,1LL<<B)  fog[mask] = h[setbits(mask)][mask];
    return fog;}
