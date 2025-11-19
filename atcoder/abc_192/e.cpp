#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 1e15
#define MAXN 1e5+7

int n, m, a, b, x, y;
vector<vector<vector<int>>> g;
vector<int> t;

vector<long long> dijkstra(int source) {
    priority_queue<pair<long long, int>> pq;
    pq.push({-0, source});
    vector<long long> dist((int) g.size(), INF);

    while(!pq.empty()) {
        long long w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] <= w) continue;
        dist[u] = w;

        for (int i = 0; i < (int) g[u].size(); i++) {
            long long d = g[u][i][1];
            int v = g[u][i][0];
            long long k = g[u][i][2];
            long long t = 0;

            if (w % k != 0) 
                t = k - w % k;

            if (d + w + t < dist[v])
                pq.push({-(d + w + t), v});
        
        }
    }

    return dist;
}

int main(void) {_
    int k;
    cin >> n >> m >> x >> y; x--; y--;
    g.resize(n, vector<vector<int>>());
    t.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t[i] >> k;
        a--; b--;
        g[a].push_back({b, t[i], k});
        g[b].push_back({a, t[i], k});
    }

    vector<long long> dist = dijkstra(x);
    
    cout << (dist[y] == INF ? -1 : dist[y]) << '\n';

    return 0;
}
