ll dp[maxn][maxn],KNUTH[maxn][maxn]; // problem was to divide an an array into n parts,
FOR(d,3,n+1)                         // to cut an array pay it's sum
    FOR(l,0,n-d+1)
        {
            ll r= l + d-1;
            FOR(k,KNUTH[l][r-1],KNUTH[l+1][r]+1)
            {
                ll t=dp[l][k]+dp[k+1][r]+ prefsum(l,r);
                if(t<dp[l][r]){dp[l][r]=t;KNUTH[l][r]=k;}
            }
        }