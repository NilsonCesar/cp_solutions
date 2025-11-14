#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

const int INF = 0x3F3F3F3F;
int n, m, q;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijkstra(Graph &g, vector<int> hosp) {
    priority_queue<Edge> pq;
    for (int amb: hosp) {
        pq.push({-0, amb - 1});
    }

    vector<int> dist(n, INF);

    while(!pq.empty()) {
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] <= w) 
            continue;
        dist[u] = w;

        for (auto [v, d]: g[u]) {
            if (w + d < dist[v]) {
                pq.push({-d - w, v});
            }
        }
    }

    return dist;
}

void add_edge(Graph &g, int u, int v, int w) {
    u--; v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
}

void solve() {
    Graph g = Graph(n, vector<Edge>());
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(g, a, b, w);
    }

    vector<int> hosp(q);
    for (int &i: hosp) 
        cin >> i;

    vector<int> dist = dijkstra(g, hosp);

    int ans = -1;

    for (int d: dist)
        ans = max(ans, d);
    
    cout << ans << '\n';
}


int main(void) {
    // mainIO();

    while(cin >> n >> m >> q) {
        solve();
    }

    return 0;
}
