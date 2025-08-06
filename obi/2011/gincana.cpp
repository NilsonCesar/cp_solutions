#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> f;
vector<int> labels, visited;

void dfs(int u, int l) {
    if (visited[u]) return;
    visited[u] = true;
    labels[u] = l;

    for (int i = 0; i < (int) f[u].size(); i++) 
        dfs(f[u][i], l);
}

int main(void) {
    mainIO();
    int n, m, u, v;
    cin >> n >> m;
    f.resize(n + 1, vector<int>());
    labels.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i <= n; i++) labels[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (labels[i] == i) 
            dfs(i, i);

    int ans = 0;

    for (int i = 1; i <= n; i++) 
        ans += labels[i] == i;

    cout << ans << '\n';

    return 0;
}
