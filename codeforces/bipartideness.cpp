#include <bits/stdc++.h>
using namespace std;

int qtd_1;
vector<vector<int>> g;
vector<int> label;
vector<bool> visited;

void dfs(int node, int l) {
    if(l) qtd_1++;
    visited[node] = true;
    label[node] = l;
    for(int i = 0; i < (int) g[node].size(); i++)
        if(!visited[g[node][i]])
            dfs(g[node][i], !l);
}

int main()
{
    int n, u, v;
    cin >> n;
    g.resize(n + 1, vector<int>());
    label.resize(n + 1, 0);
    visited.resize(n + 1, false);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    long long ans = 0, acc;
    for(int i = 1; i <= n; i++) {
        if(label[i]) continue;
        acc = 0;
        for(int j = 0; j < (int) g[i].size(); j++) 
            if(label[g[i][j]])
                acc++;
        ans += qtd_1 - acc;
    }
    cout << ans << '\n';
    return 0;
}