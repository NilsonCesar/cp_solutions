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

int v, k;
vector<vector<pair<int, int>>> g;
vector<int> dist;

int dijkstra(int a, int b) {
    priority_queue<pair<int, int>> pq;
    pq.push({-0, a});

    while (!pq.empty()) {
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == b && dist[b] <= w) return dist[b];
        if (dist[u] <= w) continue;
        dist[u] = w; 

        for (pair<int, int> v : g[u]) {
            int n = v.first, p = v.second;
            if (p + w < dist[n])
                pq.push({-(p + w), n});
        }
    }

    return dist[b];
}

void solve() {
    int a, b, c;
    cin >> v >> k;
    g.resize(v + 1, vector<pair<int, int>>());
    dist.resize(v + 1, INF);

    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    cin >> a >> b;
    int ans = dijkstra(a, b);

    if (ans != INF) cout << ans;
    else cout << "NO";
    cout << '\n';

    g.clear();
    dist.clear();
}

int main(void) {
    mainIO();
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
