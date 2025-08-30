#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, c, u, v, ans;
vector<int> has_cat, visited;
vector<vector<int>> g;

void dfs(int u, int act_c = 0) {
    if (visited[u]) return;
    visited[u] = 1;
    act_c += has_cat[u];
    if (!has_cat[u]) act_c = 0;
    if (act_c > c) return;
    if ((int) g[u].size() == 1 && u != 1) {
        ans++;
        return;
    }

    for (int v : g[u]) {

        dfs(v, act_c);
    }
}

int main(void) {
    cin >> n >> c;
    has_cat.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    g.resize(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) cin >> has_cat[i];

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    cout << ans << '\n';

    return 0;
}
