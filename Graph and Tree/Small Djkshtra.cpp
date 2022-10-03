vll SmallDijkstra( ll src, ll lim) {
vvll qs(lim);vll dist(n+1, -1);
dist[src] = 0; qs[0].push_back(src);
for (ll d = 0, maxd = 0; d <= maxd; ++d) {
    for (auto& q = qs[d % lim]; q.size(); ) {
        ll node = q.back(); q.pop_back();
        if (dist[node] != d) continue;
        for (auto [vec, cost] : v[node]) {
            if (dist[vec] != -1 && dist[vec] <= d + cost) continue;
            dist[vec] = d + cost;
            qs[(d + cost) % lim].push_back(vec);
            maxd = max(maxd, d + cost);
        }}}
return dist;}