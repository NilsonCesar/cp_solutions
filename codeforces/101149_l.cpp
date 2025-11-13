#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int n, m, a, b, u, v;
    cin >> n >> m >> a >> b;
    vector<vector<int>> g(n + 1, vector<int>()), gr(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> dist_0(n + 1, 0), dist_a(n + 1, 0), dist_b(n + 1, 0);

    vector<bool> visited(n + 1, false);
    queue<vector<int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int u = node[0], d = node[1];
        if (visited[u]) continue;
        visited[u] = true;
        dist_0[u] = d;
        for (int v: g[u]) {
            if (visited[v]) continue;
            q.push({v, d + 1});
        }
    }
 
    vector<bool> visited_a(n + 1, false);
    q.push({a, 0});

    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int u = node[0], d = node[1];
        if (visited_a[u]) continue;
        visited_a[u] = true;
        dist_a[u] = d;
        for (int v: gr[u]) {
            if (visited_a[v]) continue;
            q.push({v, d + 1});
        }
    }

    vector<bool> visited_b(n + 1, false);
    q.push({b, 0});

    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        int u = node[0], d = node[1];
        if (visited_b[u]) continue;
        visited_b[u] = true;
        dist_b[u] = d;
        for (int v: gr[u]) {
            if (visited_b[v]) continue;
            q.push({v, d + 1});
        }
    }

    int ans = 1e8;

    for (int i = 0; i <= n; i++) {
        if (visited[i] && visited_a[i] && visited_b[i]) {
            ans = min(dist_0[i] + dist_a[i] + dist_b[i], ans);
        }
    }

    cout << ans << '\n';

    return 0;
}
