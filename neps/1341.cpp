#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 1e5+7

int s, t, a, b, c, q, m, x;
vector<long long> dist(MAXN, 0), p(MAXN, 0), tamanho_ciclo(MAXN, 0);
vector<bool> visited(MAXN, false);
vector<vector<pair<int, long long>>> g;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (auto [v, w] : g[u]) {
        if (visited[v] && p[u] != v) {
            long long d = dist[u] - dist[v] + w;
            int atual = u;
            while(!tamanho_ciclo[v]) {
                tamanho_ciclo[atual] = d;
                atual = p[atual];
            }
        } else if (!visited[v]) {
            p[v] = u;
            dist[v] = dist[u] + w;
            dfs(v);
        }
    }
}

void bfs(int x, int m) {
    queue<pair<int, long long>> q;
    q.push({x, 0});
    long long ans = INF;
    vector<long long> dist((int) g.size() + 1, INF);
    while(!q.empty()) {
        int u = q.front().first;
        long long d = q.front().second;
        q.pop();
        if (dist[u] <= d) continue;
        dist[u] = d;
        if (tamanho_ciclo[u] >= m && dist[u] * 2 < ans) {
            ans = min(ans, tamanho_ciclo[u] + 2 * dist[u]);
            for (auto [v, w] : g[u]) 
                if (d + w < dist[v])
                    q.push({v, d + w});
        } else if (tamanho_ciclo[u] == 0 && dist[u] * 2 < ans) {
            for (auto [v, w] : g[u]) 
                if (d + w < dist[v])
                    q.push({v, d + w});
        } else if (tamanho_ciclo[u] < m && dist[u] * 2 < ans) {
            for (auto [v, w] : g[u]) 
                if (d + w < dist[v])
                    q.push({v, d + w});
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main(void) {_
    cin >> s >> t;
    g.resize(s + 1, vector<pair<int, long long>>());
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    for (int i = 1; i <= s; i++)
        dfs(i);
    cin >> q;
    while(q--) {
        cin >> x >> m;
        bfs(x, m);
    }

    return 0;
}
