const int N = 100010, M = 22;
vector<int> eg[N]; //edge graph
int u[N],v[N],sz[N], c_par[N], level[N];
set<int> a[N]; // node value
bool del[N];
set<int> f[M][N]; // function that need to be calculated
int nodes = 0;
int adj(int e,int x){
    if(u[e]==x) return v[e];
    else return u[e];
}
void sz_cal(int node,int par=-1){
    nodes++;
    sz[node]=1;
    for(auto &e:eg[node]){
        int c=adj(e,node);
        if(del[e] || c==par) continue;
        sz_cal(c,node);
        sz[node]+=sz[c];
}}
int cent(int node,int par=-1){
    for(auto &e:eg[node]){
        int c=adj(e,node);
        if(del[e] || c==par) continue;
        if(sz[c]>(nodes)/2){
            return cent(c,node);
        }
    }
    return node;}
// function calculation
set<int>unite(set<int>&a,set<int>&b){}
void dfs(int node,int par,int lvl,set<int>cur){
    f[lvl][node]=cur;
    for(auto &e:eg[node]){
        int c=adj(e,node);
        if(del[e] ||c==par) continue;
        dfs(c,node,lvl,unite(cur,a[c]));
}}
void decompose(int vert, int cent_par = 0) {
    nodes = 0;
    sz_cal(vert);
    int child = cent(vert);
    c_par[child] = cent_par;
    level[child] = level[cent_par] + 1;
    dfs(child,-1,level[child],a[child]); // function calculator
    for (auto e:eg[child]) {
        int c=adj(e,child);
        if(del[e]) continue;
        del[e]=true;decompose(c, child);
}}
int lca(int x,int y){
    if(level[x]>level[y]) swap(x,y);
    while(level[y]>level[x]) y=c_par[y];
    while(x!=y) x=c_par[x],y=c_par[y];
    return x;}
set<int> qry(int x,int y){
    int l=lca(x,y);
    return unite(f[level[l]][x],f[level[l]][y]);}