// DAG Reachability - 0-indexed
Complexity: amortized O(n) per update*/
struct Italiano {
  int n;
  vector<vector<int>> par;
  vector<vector<vector<int>>> child;
  Italiano(int n) : n(n), par(n, vector<int>(n, -1)), child(n, vector<vector<int>>(n)) { }
  bool is_reachable(int s, int t) {
    return s == t || par[s][t] >= 0;
  }
  bool add_edge(int s, int t) {
    if (is_reachable(t, s)) return 0; // break DAG condition
    if (is_reachable(s, t)) return 1;  // no-modification performed
    for (int p = 0; p < n; ++p) {
      if (is_reachable(p, s) && !is_reachable(p, t)) meld(p, t, s, t);
    }
    return 1;
  }
  void meld(int root, int sub, int u, int v) {
    par[root][v] = u;
    child[root][u].push_back(v);
    for (int c : child[sub][v]) {
      if (!is_reachable(root, c)) meld(root, sub, v, c);
    }
  }
};
