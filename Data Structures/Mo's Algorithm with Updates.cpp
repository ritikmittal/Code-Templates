const int N=100005,bs=2500;
int a[N],temp[N];
struct Query {int l, r, t,lBno,rBno,idx; };
struct Updates{int p,x,old_val;};
Query qry[N];
Updates upd[N];
int L=-1,R=-1,T=0;
bool cmp(Query &p,Query &q) {
    if (p.lBno == q.lBno) {
        if (p.rBno == q.rBno) return p.t < q.t;
        return p.rBno < q.rBno;
    }
    return p.lBno < q.lBno;
}
//x as value
void add(int x) {}
void remove(int x) {}
void update(int p,int x) {
    if (p >= L && p <= R) {
        remove(a[p]);add(x);
    }
    a[p] = x;
}
int get_answer() {}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) { cin >> a[i];}
    int up = 0;
    int qr = 0;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            qry[qr].l = l;
            qry[qr].lBno = l / bs;
            qry[qr].r = r;
            qry[qr].rBno = r / bs;
            qry[qr].t = up;
            qry[qr].idx = qr;
            qr++;
        } else {
            int p, x;
            cin >> p >> x;
            --p;
            up++;
            upd[up].p = p;
            upd[up].old_val = temp[p];
            temp[p] = x;
            upd[up].x = temp[p];
        }
    }
    L = 0, R = 0, T = 0;
    add(a[L]);
    q = qr;
    int ans[q];
    sort(qry, qry + q, cmp);
    for (int i = 0; i < q; i++) {
        auto &c = qry[i];
        int l = c.l;
        int r = c.r;
        int t = c.t;
        while (T < t) {T++;update(upd[T].p, upd[T].x);}
        while (T > t) {update(upd[T].p, upd[T].old_val);T--;}
        while (R < r) {R++;add(a[R]);}
        while (L > l) {--L;add(a[L]);}
        while (R > r) {remove(a[R]);--R;}
        while (L < l) {remove(a[L]);++L;}
        ans[c.idx] = get_answer();
    }
}