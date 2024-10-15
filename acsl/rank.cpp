#include <bits/stdc++.h>
using namespace std;

bool in_cycle;
vector<bool> visited;
vector<vector<int>> g;

void dfs(int node, int root) {
    visited[node] = true;
    for(int i = 0; i < (int) g[node].size(); i++) {
        if(g[node][i] == root)
            in_cycle = true;
        if(!visited[g[node][i]])
            dfs(g[node][i], root);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, u, v, su, sv;
    cin >> n >> k;
    visited.resize(n + 1, false);
    g.resize(n + 1, vector<int>());
    
    for(int i = 0; i < k; i++) {
        cin >> u >> v >> su >> sv;
        if(su < sv) g[v].push_back(u);
        else g[u].push_back(v);
    }
    
    set<int> ans;
    
    for(int i = 1; i <= n; i++) {
        dfs(i, i);
        if(in_cycle) ans.insert(i);
        visited.clear();
        visited.resize(n + 1, false);
        in_cycle = false;
    }

    cout << (int) ans.size() << '\n';

    return 0;
}