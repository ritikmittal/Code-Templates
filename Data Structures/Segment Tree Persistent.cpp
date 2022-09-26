const int N=100001;
const int SZ=21*N;
int ptr=1;
int l[SZ],r[SZ],val[SZ],a[N];
int node(int left,int right) {
    int pos = ptr;
    l[pos] = left;
    r[pos] = right;
    // function
    val[pos] = val[left] + val[right];
    ptr++;
    return pos;
}
int leaf(int value) {
    int pos = ptr;
    l[pos] = r[pos] = 0;
    val[pos] = value;
    ptr++;
    return pos;
}
int build(int s,int e) {
    if (s == e) return leaf(a[s]);
    int m = (s + e) / 2;
    int left = build(s, m);
    int right = build(m + 1, e);
    return node(left, right);
}
int update(int old,int s,int e,int idx,int inc) {
    if (s == e) return leaf(val[old] + inc);
    int m = (s + e) / 2;
    int left, right;
    if (idx <= m) {
        left = update(l[old], s, m, idx, inc);
        right = r[old];
    } else {
        left = l[old];
        right = update(r[old], m + 1, e, idx, inc);
    }
    return node(left, right);
}
int query(int ith,int jth,int s,int e,int k) {
    if (s == e) {
        return s;
    }
    int m = (s + e) / 2;
    int leftVal = val[l[jth]] - val[l[ith]];
    if (leftVal >= k) {
        return query(l[ith], l[jth], s, m, k);
    } else {
        return query(r[ith], r[jth], m + 1, e, k - leftVal);
    }
}
int root[n + 1];
root[0] = build(0, n);
for (int i = 1; i <= n; i++) {
    root[i] = update(root[i - 1], 0, n, a[i - 1], 1);
}
for (int i = 0; i < q; i++) {
    int l, r, v;
    cin >> l >> r >> v;
    cout << rm[query(root[l - 1], root[r], 0, n, v)] << endl;
}