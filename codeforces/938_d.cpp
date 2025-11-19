#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 2e18
#define MAXN 2e5+7

int n, m;
vector<vector<pair< int, long long >>> g;
vector<long long> c;
vector<long long> dist(MAXN, INF);

void dijkstra() {
    priority_queue<pair<long long, int>> pq;

    for (int i = 1; i <= n; i++) {
        pq.push({-c[i], i});
        dist[i] = c[i];
    }

    while(!pq.empty()) {
        long long w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < w) continue;

        for (auto [v, d] : g[u]) {
            if (d + dist[u] < dist[v]) {
                dist[v] = d + dist[u];
                // cout << "Here: " << (d + w) * 2 + c[v] << '\n';
                pq.push({-(d + dist[u]), v});
            }
        }
    }
}

int main(void) {_
    long long u, v, w;
    cin >> n >> m;
    g.resize(n + 1, vector<pair<int, long long>>());
    c.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, 2 * w});
        g[v].push_back({u, 2 * w});
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}
