const int N=200001;
vector<int>v[N]; // given graph
vector<int>rv[N]; // reverse graph
set<int>ng[N]; // new component graph
stack<int>stk;
bool vis[N];
int compNo[N]; //  component number
vector<vector<int>>strongly_components;
void dfs(int node) {
    vis[node] = true;
    for (auto &c: v[node]) {
        if (!vis[c]) {
            dfs(c);
        }
    }
    stk.push(node);
}
void rdfs(int node,vector<int>&comp) {
    vis[node] = true;
    comp.push_back(node);
    for (auto &c: rv[node]) {
        if (!vis[c]) {
            rdfs(c, comp);
        }
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,false,sizeof vis);
    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (vis[node]) continue;
        vector<int> component;
        rdfs(node, component);
        for(auto &c:component){
            compNo[c]=strongly_components.size();
        }
        strongly_components.push_back(component);
    }
    for(int i=0;i<n;i++){
        for(auto &c:v[i]){
            if(compNo[i]!=compNo[c]){
                ng[compNo[i]].insert(compNo[c]);
            }
        }
    }
}