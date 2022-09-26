struct Query {
    int i, l, r, bno;
};
bool cmp(Query &a,Query &b) {
    if (a.bno != b.bno) {
        return a.bno < b.bno;
    } else if (a.bno & 1) {
        return a.r < b.r;
    } else {
        return a.r > b.r;
    }
}
int n,q;
const int bs=700;// change is depending on problem
const int N=500001;
Query qry[N];
int a[N];
int ans[N];
int lp,rp,cnt;
void add(int val) {
    freq[val]++;
    if (freq[val] == 1) cnt++;
}
void remove(int val) {
    freq[val]--;
    if (freq[val] == 0) cnt--;
}
int get_answer() {
    return cnt;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        qry[i].i = i;
        qry[i].l = l;
        qry[i].r = r;
        qry[i].bno = l / bs;
    }
    // sort the queries
    sort(qry, qry + q, cmp);
    // initialise the data-structure
    lp = rp=cnt=0;
    add(a[0]);
    // answer the queries
    for (int i = 0; i < q; i++) {
        int l = qry[i].l;
        int r = qry[i].r;
        while (rp < r) add(a[++rp]);
        while (lp > l) add(a[--lp]);
        while (rp > r) remove(a[rp--]);
        while (lp < l) remove(a[lp++]);
        ans[qry[i].i] = cnt;
    }
}