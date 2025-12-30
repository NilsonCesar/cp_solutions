#include <bits/stdc++.h>
 
using namespace std;
 
#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
 
int n, m;
vector<vector<int>> g;
vector<int> vis, p;
int l, r;
 
bool dfs(int u, int par = 0) {
    p[u] = par;
    vis[u] = 1;

    for (int v : g[u]) {
        if (v == par) continue;

        if (vis[v] == 1) {
            l = v;
            r = u;
            return true;
        }

        if (!vis[v]) {
            if(dfs(v, u)) return true;
        }
    }

    vis[u] = 2;
    return false;
}
 
int main(void) {_
    cin >> n >> m;
    g.resize(n + 1, vector<int>());
    vis.resize(n + 1, 0);
    p.resize(n + 1, 0);
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && dfs(i, 0)) {
            vector<int> sol;

            for (int cur = r; cur != l; cur = p[cur]) {
                sol.push_back(cur);
            }
            sol.push_back(l);
            sol.push_back(r);

            cout << (int) sol.size() << '\n';
            for (int u: sol)
                cout << u << ' ';
            cout << '\n';
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE" << '\n';
 
    return 0;
}