struct node {int l, r, cnt;
    node():l(0),r(0),cnt(0) {}};
struct BT{
vector<node>t;int M;
BT(int m=30):M(m) {t.eb();}
void insert(int a) {
    int idx = 0;t[idx].cnt++;
    for (int i = M; i >= 0; i--) {
    if (a & (1ll << i)) {
    if (!t[idx].r){t[idx].r = sz(t);t.eb();}
    idx = t[idx].r;
    } else {
    if (!t[idx].l) {t[idx].l = sz(t);t.eb();}
    idx = t[idx].l;}
    t[idx].cnt++;}
}
bool isPresent(int a) {
int idx = 0;
for (int i = M; i >= 0; i--) {
    if (a & (1ll << i)) {
    if ((!t[idx].r)||(t[t[idx].r].cnt==0)) 
        return false;
    idx = t[idx].r;
    } else {
    if ((!t[idx].l||(t[t[idx].l].cnt==0)) 
        return false;
    idx = t[idx].l;
    }}
    return true;}
bool remove(int a) {
    if (!isPresent(a)) return false;
    int idx = 0;t[idx].cnt--;
    for (int i = M; i >= 0; i--) {
        if (a & (1ll << i)) idx = t[idx].r;
        else idx = t[idx].l;
        t[idx].cnt--;
    }
    return true;
}
int min_xor(int a) {
int ans = 0,idx = 0;
if (t[idx].cnt == 0) return -1;
for (int i = M; i >= 0; i--) {
    if (!(a & (1ll << i))) {
    if (t[idx].l &&( t[t[idx].l].cnt > 0)) {
        idx = t[idx].l;
    } else {
        ans |= (1ll << i);idx = t[idx].r;}
    } else {
    if (t[idx].r && (t[t[idx].r].cnt > 0)) {
        idx = t[idx].r;
    } else {
        ans |= (1ll << i);idx = t[idx].l;}
    }
}
return ans;
}
};
