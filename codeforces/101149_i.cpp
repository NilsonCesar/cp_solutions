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
vector<int> visited;

int main(void) {
    mainIO();
    int n, m, u, v;
    cin >> n >> m;
    visited.resize(n + 1, false);
    g.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int min_node = 1;
    for (int i = 1; i <= n; i++) 
        if ((int) g[i].size() < (int) g[min_node].size())
            min_node = i;

    visited[min_node] = true;
    for (int i = 0; i < (int) g[min_node].size(); i++)
        visited[g[min_node][i]] = true;
    
    for (int i = 1; i <= n; i++)
        cout << !visited[i] << ' ';
    cout << '\n';

    return 0;
}
