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
int n, m, x;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijkstra(Graph &g, int source) {
    priority_queue<Edge> pq;
    pq.push({0, source});

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

int main(void) {
    mainIO();
    cin >> n >> m >> x;

    Graph g = Graph(n, vector<Edge>());
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(g, a, b, w);
    }

    vector<int> friends(x);
    for (int &i: friends) 
        cin >> i;

    vector<int> dist_friends = dijkstra(g, 0);
    vector<int> dist_icecream = dijkstra(g, n - 1);

    int ans = INF;

    for (int friend_: friends) 
        ans = min(ans, dist_friends[friend_ - 1] + dist_icecream[friend_ - 1]);
    
    cout << ans << '\n';

    return 0;
}
