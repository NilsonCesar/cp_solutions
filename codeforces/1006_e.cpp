#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, q, r, u, k;
vector<vector<int>> g;
vector<bool> visited;
vector<int> path, sizeG, idx;

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;
    path.push_back(u);
    idx[u] = -1 + (int) path.size();
    for (int i = 0; i < (int) g[u].size(); i++) {
        sizeG[u] += dfs(g[u][i]);
    }
    return sizeG[u];
}

int main(void) {
    mainIO();
    cin >> n >> q;
    g.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);
    sizeG.resize(n + 1, 1);
    idx.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> r;
        g[r].push_back(i);
        g[i].push_back(r);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(1);

    while (q--) {
        cin >> u >> k;
        if (sizeG[u] < k) {
            cout << -1;
        } else {
            cout << path[idx[u] + k - 1];
        }
        cout << '\n';
    }

    return 0;
}
