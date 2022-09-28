int dp[20][11][2][2][2];
int solve(string &a,string &b,int i,bool bigA,bool smallB,bool start,int lastDig) {
    if (i == a.length()) return 1;
    int &ans = dp[i][lastDig+1][bigA][smallB][start];
    if (~ans) return ans; ans = 0;
    int l = 0, r = 9;
    if (!bigA) l = (a[i] - '0');
    if (!smallB) r = (b[i] - '0');
    for (int j = l; j <= r; j++) {
        if (j == lastDig) continue;
        bool n_bigA = bigA | (j > l),n_smallB = smallB | (j < r);
        bool n_start = (start | (j != 0));
        int n_lastDig = j;
        if (!n_start) n_lastDig = -1;
        ans += solve(a, b, i + 1, n_bigA, n_smallB, n_start, n_lastDig);
    }
    return ans;
}