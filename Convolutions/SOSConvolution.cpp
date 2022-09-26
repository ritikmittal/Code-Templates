#define FOR(i,n) for(ll i=0;i<n;i++)

const int B = 20; // Every input vector must need to be of size 1<<B
// O(B * 2 ^ B)
vll SOSDP(vll f) {
    FOR(i,B) FOR(mask,1LL<<B)
            if ((mask & (1 << i)) != 0)f[mask] += f[mask ^ (1 << i)];
            //for supermasks make ((mask & (1 << i)) ==0
    return f;
}
// you can change the operator from + to min/gcd to find min/gcd of all f[submasks]

//odd negation means if bit has odd set bits f[bit]=-f[bit]
//it can also be done by take oddnegation(f),SOS(f),oddnegation(f)
vll INVSOSDP(vll f) {
    FOR(i,B) FOR(mask,1LL<<B)
            if ((mask & (1 << i)) != 0)f[mask] -= f[mask ^ (1 << i)];
    return f;
}

// f*g(s)=sum_{s' $ s} {f(s')*g(s\s')}
// O(B * B * 2 ^ B)
vll subset_sum_convolution(vll f, vll g) {
    vvll fhat(B + 1, vll (1 << B, 0));
    vvll ghat(B + 1, vll (1 << B, 0));
    // Make fhat[][] = {0} and ghat[][] = {0}
    FOR(mask,1LL<<B) {
        fhat[__builtin_popcount(mask)][mask] = f[mask];
        ghat[__builtin_popcount(mask)][mask] = g[mask];
    }
    // Apply zeta transform on fhat[][] and ghat[][]
    for (int i = 0; i < B; i++) {
        fhat[i]=SOSDP(fhat[i]);
        ghat[i]= SOSDP(ghat[i]);
    }
    vvll h(B + 1, vll (1 << B, 0));
    // Do the convolution and store into h[][] = {0}
    FOR(mask,1LL<<B) FOR(i,B)FOR(j,i+1)
                h[i][mask] += 1LL * fhat[j][mask] * ghat[i - j][mask] ;
    // Apply inverse SOS dp on h[][]
    for (int i = 0; i < B; i++) {
        h[i]=INVSOSDP(h[i]);
    }
    vll fog(1 << B, 0);
    FOR(mask,1LL<<B)  fog[mask] = h[__builtin_popcount(mask)][mask];
    return fog;}