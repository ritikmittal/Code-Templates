vector<vector<int>> m;
int n;
m.resize(n,vector<int>(n,0));
mat operator*(mat const &b) {
    mat ans(n);
    rep(i,0,n) rep(j,0,n) rep(k,0,n)
    (ans.m[i][j] += m[i][k] * b.m[k][j])%=mod;
    return ans;
}
mat power(int p) {
    mat ans(n); mat curr = *this;
    for (int i = 0; i < n; i++) ans.m[i][i] = 1;
    while (p) {
        if (p & 1) ans = ans * curr;
        p /= 2;
        curr = curr * curr;
    }
    return ans;
}