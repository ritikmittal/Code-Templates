//set dp[i][j]=inf, dp[i][i]=0;
FOR(i, 0, n)FOR(j, 0, n)FOR(k, 0, n) 
dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);