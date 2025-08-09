#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> g;
vector<bool> visited;
bool is_cycle;

void dfs(int u, int p = -1) {
    if (visited[u]) return;
    if ((int) g[u].size() != 2) {
        return;
    }
    visited[u] = true;

    for (int i = 0; i < (int) g[u].size(); i++) {
        if (visited[g[u][i]] && g[u][i] != p) {
            is_cycle = true;
            return;
        } else if (g[u][i] != p) {
            dfs(g[u][i], u);
        }
    }
}

int main(void) {
    mainIO();
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        is_cycle = false;
        dfs(i);
        ans += is_cycle;
    }

    cout << ans << '\n';

    return 0;
}
