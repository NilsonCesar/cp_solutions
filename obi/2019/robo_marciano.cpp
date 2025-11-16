#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define INF 0x3f3f3f3f
typedef vector<int> area;

long best_distance(area a1, area a2) {
    // manhattan
    int xi1 = a1[0], yi1 = a1[1], xf1 = a1[2], yf1 = a1[3]; 
    int xi2 = a2[0], yi2 = a2[1], xf2 = a2[2], yf2 = a2[3]; 

    if (xi1 > xf1) swap(xi1, xf1);
    if (yi1 > yf1) swap(yi1, yf1);
    if (xi2 > xf2) swap(xi2, xf2);
    if (yi2 > yf2) swap(yi2, yf2);
    long dx = 0;

    if (xf1 < xi2) {
        dx = xi2 - xf1;
    }
    if (xf2 < xi1) {
        dx = xi1 - xf2;
    }

    long dy = 0;
    if (yf1 < yi2) {
        dy = yi2 - yf1;
    }
    if (yf2 < yi1) {
        dy = yi1 - yf2;
    }

    return dx + dy;
}

vector<long> dijkstra(vector<vector<pair<int, long long>>> &g, int source) {
    vector<long> dist((int) g.size(), INF);
    priority_queue<pair<long long, int>> pq;
    pq.push({-0, source});

    while(!pq.empty()) {
        long w = -pq.top().first, u = pq.top().second;
        pq.pop();

        if (dist[u] <= w) continue;
        dist[u] = w;

        for (auto [v, d]: g[u])
            if (d + w <= dist[v])
                pq.push({-(d + w), v});
    }

    return dist;
}

int main(void) {
    mainIO();
    int x1, y1, x2, y2, n, u = -1, v = -1;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    vector<area> areas(n + 7);
    vector<vector<pair<int, long long>>> g(n + 7, vector<pair<int, long long>>());
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        areas[i] = {a, b, c, d};
        if (a <= x1 && x1 <= c && b <= y1 && y1 <= d)
            u = i;
        if (a <= x2 && x2 <= c && b <= y2 && y2 <= d) 
            v = i;
    }
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (i != j) 
                g[i].push_back({j, best_distance(areas[i], areas[j])});
    
    if (u == -1) {
        u = n + 1;
        areas[n + 1] = {x1, y1, x1, y1};
        for (int i = 0; i < n; i++) {
            g[i].push_back({u, best_distance(areas[i], areas[u])});
            g[u].push_back({i, best_distance(areas[u], areas[i])});
        }
    }

    if (v == -1) {
        v = n + 2;
        areas[n + 2] = {x2, y2, x2, y2};
        for (int i = 0; i < n; i++) {
            g[i].push_back({v, best_distance(areas[i], areas[v])});
            g[v].push_back({i, best_distance(areas[v], areas[i])});
        }
    }

    if (u == n + 1 && v == n + 2) {
        g[u].push_back({v, best_distance(areas[u], areas[v])});
        g[v].push_back({u, best_distance(areas[v], areas[u])});
    }

    vector<long> dist = dijkstra(g, u);
    
    cout << dist[v] << '\n';

    return 0;
}
