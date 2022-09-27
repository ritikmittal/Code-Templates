int n,m;// number of nodes, edges
int u[m],v[m],w[m];//u to v with weight w
int min_edge[n];
dsu g(n);
int tot=0;//this is output
while(g.comp!=1){
    memset(min_edge,-1,sizeof min_edge);
    for(int i=0;i<m;i++){
        if(g.par(u[i])==g.par(v[i])) continue;
        int x=g.par(u[i]);
        if(min_edge[x]==-1 || w[i]<w[min_edge[x]]){min_edge[x]=i;}
        int y=g.par(v[i]);
        if(min_edge[y]==-1 || w[i]<w[min_edge[y]]){min_edge[y]=i;}
    }
    for(int i=0;i<n;i++)
        if(min_edge[i]!=-1)
            if(g.unite(u[min_edge[i]],v[min_edge[i]]))
                tot+=w[min_edge[i]];
}

