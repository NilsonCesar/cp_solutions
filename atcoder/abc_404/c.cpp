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
int countEle = 0;

void dfs(int u) {
    countEle++;
    visited[u] = true;
    for (int i = 0; i < (int) g[u].size(); i++) {
        if (!visited[g[u][i]]) dfs(g[u][i]);
    }
}

int main(void) {
    mainIO();
    int n, m, u, v;
    cin >> n >> m;
    g.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);
    map<int, int> d;

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        d[u]++;
        d[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n != m) {
        cout << "No" << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] != 2) {
            cout << "No" << '\n';
            return 0;
        }
    }

    dfs(1);

    cout << (countEle == n ? "Yes" : "No") << '\n';

    return 0;
}