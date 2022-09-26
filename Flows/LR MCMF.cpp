// IF DAG : calculate d with dp to reduce time complexity to O(n+m) in init_potential;
// if unit capacity and unit cost -> use small dijkstra -> O( (n + m) * flow )
//Works for both directed, undirected and with negative cost too
//doesn't work for negative cycles
//for undirected edges just make the directed flag false
//Complexity: O(min(E^2 *V log V, E logV * flow))
using T = long long;
const T inf = 1LL << 61;
struct MCMF {
	struct edge {
		int u, v, id;
		T cap, cost;
		edge(int _u, int _v, T _cap, T _cost, int _id) : u(_u), v(_v), cap(_cap), cost(_cost), id(_id) {}
	};
	int n, s, t, mxid;
	T flow, cost;
	vector<vector<int>> g;
	vector<edge> e;
	vector<T> d, potential, flow_through;
	vector<int> par;
	bool neg;
	MCMF() {}
	MCMF(int _n) { // 0-based indexing
		n = _n + 10; neg = false; mxid = 0;
		g.assign(n, vector<int> ());
	}
	void add_edge(int u, int v, T cap, T cost, int id = -1, bool directed = true) {
		if (cost < 0) neg = true;
		g[u].push_back(e.size());
		e.push_back(edge(u, v, cap, cost, id));
		g[v].push_back(e.size());
		e.push_back(edge(v, u, 0, -cost, -1));
		mxid = max(mxid, id);
		if (!directed) add_edge(v, u, cap, cost, -1, true);
	}
	bool dijkstra() {
		par.assign(n, -1);
		d.assign(n, inf);
		// edge cost -> [0, lim), O(V+E+maxd) -> bounded by O(lim*V + E);
//      int lim = n + 10;
//      vector<vector<int>> qs(lim);
//        d[s] = 0; qs[0].push_back(s);
//        for (int dist = 0, maxd = 0; dist <= maxd; ++dist) {
//          for (auto& q = qs[dist % lim]; q.size(); ) {
//            int node = q.back(); q.pop_back();
//            if (d[node] != dist) continue;
//            for (auto id : g[node]) {
//                int v = e[id].v;
//                T w = e[id].cost + potential[node] - potential[v];
//              if ((d[v] != inf && d[v] <= dist + w) || e[id].cap <= 0) continue;
//              d[v] = dist + w; par[v] = id;
//              qs[(d[v]) % lim].push_back(v);
//              maxd = max(maxd, (int)d[v]); } } }
		priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>> > q;
		d[s] = 0; q.push(pair<T, T>(0, s));
		while (!q.empty()) {
			int u = q.top().second; T nw = q.top().first;
			q.pop();
			if (nw != d[u]) continue;
			for (int i = 0; i < (int)g[u].size(); i++) {
				int id = g[u][i], v = e[id].v;
				T w = e[id].cost + potential[u] - potential[v];
				if (d[u] + w < d[v] && e[id].cap > 0) {
					d[v] = d[u] + w; par[v] = id;
					q.push(pair<T, T>(d[v], v)); } } }
		for (int i = 0; i < n; i++) { // update potential
			if (d[i] < inf) potential[i] += d[i]; }
		return d[t] != inf;
	}
	T send_flow(int v, T cur) {
		if (par[v] == -1) return cur;
		int id = par[v];
		T w = e[id].cost, f = send_flow(e[id].u, min(cur, e[id].cap));
		cost += f * w;
		e[id].cap -= f; e[id ^ 1].cap += f;
		return f;
	}
	void init_potential() {
		// run Bellman-Ford to find starting potential
		d.assign(n, inf);
		d[s] = 0;
		for (int i = 0, relax = true; i < n && relax; i++) {
			for (int u = 0; u < n; u++) {
				for (int k = 0; k < (int)g[u].size(); k++) {
					int id = g[u][k], v = e[id].v;
					T w = e[id].cost;
					if (d[v] > d[u] + w && e[id].cap > 0) {
						d[v] = d[u] + w; relax = true;
					} } } }
		for (int i = 0; i < n; i++) if (d[i] < inf) potential[i] = d[i];
	}
	//returns {maxflow, mincost}
	pair<T, T> solve(int _s, int _t, T goal = inf) {
		s = _s; t = _t;
		flow = 0, cost = 0;
		potential.assign(n, 0);
		if (neg) init_potential();
		while (flow < goal && dijkstra()) flow += send_flow(t, goal - flow);
		flow_through.assign(mxid + 10, 0);
		for (int u = 0; u < n; u++) {
			for (auto v : g[u]) {
				if (e[v].id >= 0) flow_through[e[v].id] = e[v ^ 1].cap;
			} }
		return make_pair(flow, cost);
	}
};
