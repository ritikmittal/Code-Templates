//Subtree of x is subarray from [tin[x],tout[x]] but twice,for path u->v, where u is ancestor of v [tin[u],tin[v]] has only opening occurrence for the nodes on the path every other node have double occurrence for path u->v, tout[u]<tin[v],subarray [tout[u],tin[v]] contain single(both) occurrence for path node ( except lca) and double occurrence for non path node
void eut_2(int node,int p){
    tin[node]=++tme;
    ord.push_back(node);
    for(auto &c:v[node])if(c!=p)eut_2(c,node);
    tout[node]=++tme;
    ord.push_back(node);
}
// lca of u,v is the min of lvl[ord[x]] in st[u]<=x<=st[v];subtree of x occurs from [tin[x],tout[x]] but with multiple occurrences,every edge occur twice so can be used for edge queries and updates
// ord.length:- 2*edges+1
int lvl[N];
void eut_3(int node,int p){
    tin[node]=++tme;
    ord.push_back(node);
    for(auto &c:v[node]){
        if(c!=p){
            lvl[c]=lvl[node]+1;
            eut_3(c,node);
            ++tme;
            ord.push_back(node);
        }
    }
    tout[node]=tme;
}