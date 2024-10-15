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
vector<int> label;

void dfs(int node, int l) {
    visited[node] = true;
    label[node] = l;
    for(int i = 0; i < (int) g[node].size(); i++)
        if(!visited[g[node][i]])
            dfs(g[node][i], !l);
}

int main(void) {
    mainIO();
    
    int t, n, m, u, v;
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        g.resize(n + 1, vector<int>());
        visited.resize(n + 1, false);
        label.resize(n + 1, 0);
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, label[1]);
        int c0 = 0, c1 = 0;
        for(int i = 1; i <= n; i++) {
            if(label[i]) c1++;
            else c0++;
        }
        if(c0 < c1) {
            cout << c0 << '\n';
            for(int i = 1; i <= n; i++)
                if(!label[i])
                    cout << i << ' ';
        } else {
            cout << c1 << '\n';
            for(int i = 1; i <= n; i++)
                if(label[i])
                    cout << i << ' ';
        }
        cout << '\n';
        g.clear();
        visited.clear();
        label.clear();
    }

    return 0;
}
