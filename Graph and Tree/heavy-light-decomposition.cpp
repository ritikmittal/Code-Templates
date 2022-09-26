//1-base
const int N=200005;
vector<int>g[N];
segte s(N); //ds
int sz[N],par[N],head[N],child[N],tin[N],tout[N],tme,val[N];
void dfs_child(int node,int p){
    sz[node]=1;
    par[node]=p;
    head[node]=node;
    for(auto &c:g[node]){
        if(c!=p){
            dfs_child(c,node);
            sz[node]+=sz[c];
            if(sz[child[node]]<sz[c]) child[node]=c;
        }
    }
}
void dfs_hld(int node,int p){
    tin[node]=++tme;
    s.a[tme]=val[node]; // out value in ds

    if(child[node]){
        head[child[node]]=head[node];
        dfs_hld(child[node],node);
    }
    for(auto &c:g[node]){
        if(c!=p && c!=child[node]){
            dfs_hld(c,node);
        }
    }
    tout[node]=tme;
}
bool ancestor(int p,int u){
    return tin[p]<=tin[u] && tout[p]>=tout[u];
}
int lca(int u,int v){
    if(ancestor(u,v)) return u;
    if(ancestor(v,u)) return v;
    while(!ancestor(par[head[u]],v))  u=par[head[u]];
    while(!ancestor(par[head[v]],u))  v=par[head[v]];
    u=par[head[u]],v=par[head[v]];
    if(ancestor(u,v)) return v;
    else return u;
}
int query_up(int node,int l){
    int ans=0;
    while(head[node]!=head[l]){
        ans=max(ans,s.query(tin[head[node]],tin[node]).val);
        node=par[head[node]];
    }
    ans=max(ans,s.query(tin[l],tin[node]).val);
    return ans;
}
int query(int u,int v){
    int l=lca(u,v);
    return max(query_up(u,l), query_up(v,l));
}
void update(int node,int x){
    s.update(tin[node],x);
}

void init(){
    dfs_child(1,1);
    dfs_hld(1,1);
    s.build();
}