struct edge{
    int u,v,cost;};
const int N=2501;int d[N],par[N],n;
vector<edge>e;
void bellman_ford(int source) {
for (int i = 0; i < n; i++) {d[i] = inf;par[i] = -1;}
d[source] = 0;
for (int i = 0; i < n - 1; i++) {
    bool any = false;
    for (auto &c: e) {
        if (d[c.u] != inf && d[c.v] > d[c.u] + c.cost) {
            d[c.v] = d[c.u] + c.cost;
            par[c.v] = c.u;
            any = true;
        }}
    if (!any) break;}
// put negative infinity to nodes having arbitrary small value
for (int i = 0; i < n; i++) {
    bool any = false;
    for (auto &c: e) {
        if (d[c.u] != inf && d[c.v] > d[c.u] + c.cost) 
            {d[c.v] = -inf;any = true;}
    }
    if (!any) break;
}}