void solve() {
    int n,m;
    cin>>n>>m;
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i];
        --v[i];
    }
    int min_edge[n];
    dsu g(n);
    int tot=0;
    while(g.comp!=1){
        memset(min_edge,-1,sizeof min_edge);
        for(int i=0;i<m;i++){
            if(g.par(u[i])==g.par(v[i])) continue;
            int x=g.par(u[i]);
            if(min_edge[x]==-1 || w[i]<w[min_edge[x]]){
                min_edge[x]=i;
            }
            int y=g.par(v[i]);
            if(min_edge[y]==-1 || w[i]<w[min_edge[y]]){
                min_edge[y]=i;
            }
        }
        for(int i=0;i<n;i++){
            if(min_edge[i]!=-1){
                if(g.unite(u[min_edge[i]],v[min_edge[i]])){
                    tot+=w[min_edge[i]];
                }
            }
        }
    }
    cout<<tot<<endl;
}