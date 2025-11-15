#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m, c, k;

vector<int> dijsktra(vector<vector<pair<int, int>>> &g, int source) {
    priority_queue<pair<int, int>> pq;
    pq.push({-0, source});
    vector<int> dist((int) g.size() + 1, INF);

    while(!pq.empty()) {
        int w = -pq.top().first, u = pq.top().second;
        pq.pop();
        if (dist[u] <= w) continue;
        dist[u] = w;

        for (pair<int, int> p: g[u])
            if (w + p.second < dist[p.first])
                pq.push({-(w + p.second), p.first});
    }

    return dist;
} 

void solve() {
    int u, v, w;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    // map<pair<int, int>, int> c_dist;
    vector<int> distc(c, 0);
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if (u < c && v < c && abs(u - v) == 1) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        } else if (u < c  && v >= c) {
            g[v].push_back({u, w});
        } else if (u >= c && v < c) {
            g[u].push_back({v, w});
        } else if (u >= c && v >= c) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }

    // for (int i = c - 1; i >= 1; i--) {
    //     if (c_dist.find({i - 1, i}) == c_dist.end()) distc[i - 1] = INF;
    //     else distc[i - 1] = distc[i] + c_dist[{i - 1, i}];
    // }

    vector<int> distn = dijsktra(g, k);
    int ans = distn[c - 1];

    // for (int i = 0; i < c - 1; i++) 
    //     ans = min(ans, distn[i] + distc[i]);

    cout << ans << '\n';
}

int main(void) {
    mainIO();

    while ((cin >> n >> m >> c >> k) && n != 0) {
        solve();
    }

    return 0;
}
