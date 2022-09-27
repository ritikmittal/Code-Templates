#define FOR(i,a,b) for(int i=a;i<b;i++)
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int dp[n][n];
    FOR(i, 0, n)FOR(j, 0, n)dp[i][j] = inf;
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dp[a][b] = min(dp[a][b], c);
        swap(a, b);
        dp[a][b] = min(dp[a][b], c);
    }
    FOR(i, 0, n)FOR(j, 0, n)FOR(k, 0, n) 
    {dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);}
}