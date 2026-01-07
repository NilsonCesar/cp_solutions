#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 1000000000000000
#define MAXN 100007

int n, m;
vector<vector<pair<int, int>>> g;

int main(void) {_
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>> pq;
    vector<long long> dist(n + 1, INF);
    pq.push({-0, 1});

    while(!pq.empty()) {
        long long w = -pq.top().first;
        int u = pq.top().second;
    
        pq.pop();
        if (dist[u] <= w) continue;
        dist[u] = w;

        for (pair<long long, int> v : g[u])
            if (-(v.second + w) < dist[v.first])
                pq.push({-(v.second + w), v.first});
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';

    return 0;
}
