#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<pair<int, char>>> g;
vector<bool> visited;
vector<char> label;
bool block;

void dfs(int u, char group) {
    label[u] = group;
    visited[u] = true;
    for(int i = 0; i < (int) g[u].size(); i++) {
        int v = g[u][i].first;
        if(!block && label[v] != -1 && ((g[u][i].second == 'S' && label[v] != label[u]) || (g[u][i].second == 'D' && label[v] == label[u]))) {
            cout << "0" << '\n';
            block = true;
            return;
        }
        if(!visited[g[u][i].first])
            dfs(g[u][i].first, g[u][i].second == 'S' ? group : !group);
    }
}

int main(void) {
    mainIO("revegetate");
    int n, m, u, v, ans = 0;
    char type;
    cin >> n >> m;
    label.resize(n + 1, -1);
    g.resize(n + 1, vector<pair<int, char>>());
    visited.resize(n + 1, false);
    
    for(int i = 0; i < m; i++) {
        cin >> type >> u >> v;
        g[u].push_back({v, type});
        g[v].push_back({u, type});
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i, 0);
        }
    }
    
    if(!block) {
        cout << "1";
        for(int i = 0; i < ans; i++)
            cout << "0";
    
        cout << '\n';
    }
    return 0;
}