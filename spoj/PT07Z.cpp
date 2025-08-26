#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, u, v, ans = 0;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int v, int dist = 0) {
    if (visited[v]) return;
    if (dist > ans) {
        ans = dist;
        u = v;
    }
    visited[v] = true;
    for (int i = 0; i < (int) g[v].size(); i++) {
        dfs(g[v][i], dist + 1);
    }
    visited[v] = false;
}

int main(void) {
    mainIO();
    cin >> n;
    g.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for (int i = 0; i <= n; i++) visited[i] = false;
    ans = 0;
    dfs(u);
    
    cout << ans << '\n';
    
    return 0;
}
