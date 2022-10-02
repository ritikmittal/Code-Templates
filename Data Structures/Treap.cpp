mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
int sub_sz ,pr_val , val; bool flip;
array<node *,2> kids;
node(int pr,int x) {
    kids = {nullptr, nullptr};
    val = x; pr_val = pr;
    flip = false; sub_sz = 1; } }; 
class Treap { public:
static void recalc(node * me) {
    if (!me) return; me->sub_sz = 1;
    for (node * t:me->kids) if (t) me->sub_sz += t->sub_sz; }
static void prop(node * me) {
    if (!me) return; if(!me->flip) return;
    if(me->flip) swap(me->kids[0], me->kids[1]);
    for (node * t:me->kids) if (t) t->flip = !t->flip ; me->flip = 0; }
static array<node *,2> split(node * me, int inLeft) {
    if(!me) return {nullptr, nullptr};
    prop(me);
    int ls = me->kids[0] ? me->kids[0]->sub_sz : 0;
    if(ls >= inLeft) {
        auto Lres = split(me->kids[0], inLeft);
        me->kids[0] = Lres[1]; recalc(me); return {Lres[0], me};
    } else {
        inLeft -= (ls + 1);
        auto Rres = split(me->kids[1], inLeft);
        me->kids[1] = Rres[0]; recalc(me); return {me, Rres[1]};
    } }
static node * merge(node * l, node * r) {
    if(!l) return r; if(!r) return l;
    prop(l); prop(r);
    if(l->pr_val < r->pr_val) {
        l->kids[1] = merge(l->kids[1], r); recalc(l); return l;
    } else {
        r->kids[0] = merge(l, r->kids[0]); recalc(r); return r;
    } } };
