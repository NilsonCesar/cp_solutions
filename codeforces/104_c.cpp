#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m, visited_components;
vector<bool> visited;
vector<vector<int>> g;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    visited_components++;
    for (int i = 0; i < (int) g[u].size(); i++)
        dfs(g[u][i]);
}

int main(void) {
    mainIO();
    int u, v;
    cin >> n >> m;

    visited.resize(n + 1, false);
    g.resize(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n != m) {
        cout << "NO" << '\n';
        return 0;
    }

    dfs(1);

    if (visited_components != n) cout << "NO" << '\n';
    else cout << "FHTAGN!" << '\n';

    return 0;
}
