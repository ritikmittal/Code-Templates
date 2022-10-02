class dsu {
public:
    vector<int> parent,size;
    stack<tuple<int, int, int, int>> stk;
    stack<int> flag;
    explicit dsu(int a) {
        parent.resize(a);
        size.resize(a);
        for (int i = 0; i < a; i++) {
            parent[i] = i,size[i]=1;
        }
    }
    int par(int i) {
        if (i == parent[i]) return i;
        return par(parent[i]);
    }
    void unite(int a, int b) {
        a = par(a),b=par(b);
        if (a != b) {
            if(size[a]>size[b]) swap(a,b);
            stk.push({a, b, size[a], parent[a]});
            parent[a] = b;
            size[b] += size[a];
            size[a] = 0;
        }
    }
    void save() {flag.push(stk.size());}
    void roll_back() {
        auto [a, b, sz, rp] = stk.top();
        stk.pop();
        parent[a] = rp;size[a] = sz;
        size[b] -= size[a];
    }
    void roll() {
        int last = flag.top();flag.pop();
        while (stk.size() > last) roll_back();      
    }
};