//1-base
struct fente {
    int n;
    vector<int> tree;
    void init(int _n) :n(_n){
        tree.resize(n + 5, 0);
    }
    void update(int idx, int inc) {
        for (int i = idx; i <= n; i += i & -i) tree[i] += inc;        
    }
    int query(int idx) {
        int sum = 0;
        assert(idx<=n);
        for (int i = idx; i >= 1; i -= i & -i) sum += tree[i];       
        return sum;
    }
    int bs(int k) {
        int pos = 0,cur = 0;
        for (int i = 30; i >= 0; i--) {
            int which = (pos | (1 << i));
            if (which <= n && cur + tree[which] < k) {
                cur += tree[which]; pos = which;
            }
        }
        return pos;
    }
};