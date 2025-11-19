#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f 
#define MAXN 1e5+7

int n, m, x, y;
long long sx, sy, fx, fy;
vector<vector<pair<long long, long long>>> g;
long long ans;
vector<long long> dist(MAXN, INF);
vector<pair<long long, long long>> tele;


void dijkstra() {
    priority_queue<pair<long long, int>> pq;
    
    for (int i = 0; i < m; i++) {
        pq.push({-min(abs(sx - tele[i].first), abs(sy - tele[i].second)), i});
    }

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] <= d) continue;
        dist[u] = d;
        
        for (auto [w, v] : g[u])
            if (w + d < dist[v])
                pq.push({-(w + d), v});
    }
}


int main(void) {_
    cin >> n >> m;
    g.resize(m, vector<pair<long long, long long>>());
    tele.resize(m, pair<long long, long long>());
    cin >> sx >> sy >> fx >> fy;
    ans = abs(sx - fx) + abs(sy - fy);

    vector<pair<long long, int>> X(m), Y(m);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        X[i] = {x, i};
        Y[i] = {y, i};
        tele[i] = {x, y};
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 1; i < m; i++) {
        int a = X[i - 1].second, b = X[i].second;
        long long d = X[i].first - X[i - 1].first;
        g[a].push_back({d, b});
        g[b].push_back({d, a});
        a = Y[i - 1].second, b = Y[i].second;
        d = Y[i].first - Y[i - 1].first;
        g[a].push_back({d, b});
        g[b].push_back({d, a});
    }

    dijkstra();

    for (int i = 0; i < m; i++)
        ans = min(ans, dist[i] + abs(tele[i].first - fx) + abs(tele[i].second - fy));

    cout << ans << '\n';

    return 0;
}
