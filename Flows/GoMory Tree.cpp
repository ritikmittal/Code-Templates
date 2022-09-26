const int N = 3e5 + 9;

using F = long long;
using W = long long; // types for flow and weight/cost
struct S {
  const int v, r; F f; const F cap; const W cost; 
  S(int v, int ri, F c, W cost = 0) :
    v(v), r(ri), f(0), cap(c), cost(cost) {}
  inline F res() const {
    return cap - f; }
};
struct FlowGraph : vector<vector<S>> {
  FlowGraph(size_t n) : vector<vector<S>>(n) {}
  void add_arc(int u, int v, F c, W cost = 0) {
    auto &t = *this;
    t[u].emplace_back(v, t[v].size(), c, cost);
    t[v].emplace_back(u, t[u].size() - 1, 0, -cost);
  }
  void add_edge(int u, int v, F c, W cost = 0) {
    auto &t = *this;
    t[u].emplace_back(v, t[v].size(), c, cost);
    t[v].emplace_back(u, t[u].size() - 1, c, -cost);
  }
  void clear() {
    for (auto &ed : *this) for (auto &e : ed) e.f = 0LL;
  }
};
//0-indexed
struct Dinic {
  FlowGraph &edges;
  int V, s, t; vector<int> l;
  vector<vector<S>::iterator> its; // levels and iterators
  Dinic(FlowGraph &edges, int s, int t) :
    edges(edges), V(edges.size()), s(s), t(t), l(V, -1), its(V) {}
  long long augment(int u, F c) { // we reuse the same iterators
    if (u == t) return c;
    for(auto &i = its[u]; i != edges[u].end(); i++) {
      auto &e = *i;
      if (e.cap > e.f && l[u] < l[e.v]) {
        auto d = augment(e.v, min(c, e.cap - e.f));
        if (d > 0) {
          e.f += d; edges[e.v][e.r].f -= d; return d;
        } } } return 0;
  }
  long long run() {
    long long flow = 0, f;
    while(true) {
      fill(l.begin(), l.end(), -1);
      l[s] = 0; queue<int> q; q.push(s);
      while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto &&e : edges[u]) if(e.cap > e.f && l[e.v] < 0)
            l[e.v] = l[u] + 1, q.push(e.v); }
      if (l[t] < 0) return flow;
      for (int u = 0; u < V; ++u) its[u] = edges[u].begin();
      while ((f = augment(s, 2e9)) > 0) flow += f;///take care of inf
    } } };
/*For a given weighted graph the Gomory-Hu tree has the following properties:
The vertex set of the tree and the graph is the same.
The maximum flow between vertices u and v in the tree(i.e. minimum edge from u to v)
is equal to the maximum flow in the graph.
0-indexed
O(n*maxflow+n^2)*/
struct edge {
  int u, v;
  long long w;
};
struct GomoryHuTree {
  int V;
  vector<int> p, w, c;
  vector<edge> tree;
  void dfs(int u, const FlowGraph &fg) {
    c[u] = 1;
    for (const auto &e : fg[u])
      if (!c[e.v] && e.res())
        dfs(e.v, fg);
  }
  GomoryHuTree(int n, const vector<edge> &ed) : V(n), p(V), w(V), c(V) {
    FlowGraph fg(V);
    for (const edge &e : ed) fg.add_edge(e.u, e.v, e.w);
    p[0] = -1, std::fill(p.begin() + 1, p.end(), 0);
    for (int i = 1; i < V; ++i) {
      w[i] = Dinic(fg, i, p[i]).run();
      std::fill(c.begin(), c.end(), 0);
      dfs(i, fg);
      for (int j = i + 1; j < V; ++j)
        if (c[j] && p[j] == p[i]) p[j] = i;
      if (p[p[i]] >= 0 && c[p[p[i]]]) {
        int pi = p[i]; swap(w[i], w[pi]);
        p[i] = p[pi]; p[pi] = i; }
      fg.clear(); } }
  const vector<edge> &get_tree() {
    if (tree.empty())
      for (int i = 0; i < V; ++i) {
        if (p[i] >= 0)
          tree.push_back(edge{i, (int)p[i], w[i]}); }
    return tree; }
};
