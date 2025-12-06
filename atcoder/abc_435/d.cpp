#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, m, q, u, v;
vector<vector<int>> g, gr;
vector<bool> paint;

void dfs(int u) {
    if (paint[u]) return;
    paint[u] = true;
    for (int v : gr[u])
        dfs(v);
}

int main(void) {_
    cin >> n >> m;
    paint.resize(n + 1, false);
    g.resize(n + 1, vector<int>());
    gr.resize(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        if (u == 1) {
            dfs(v);
        } else {
            cout << (paint[v] ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}
