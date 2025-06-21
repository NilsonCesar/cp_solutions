#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m;
int visited[1005][1 << 11];
vector<vector<pair<int, int>>> g;
int ans = 0x3f3f3f3f;

void dfs(int a, int value) {
    visited[a][value] = true;
    if (a == n) ans = min(ans, value);

    for (int i = 0; i < (int) g[a].size(); i++) 
        if (!visited[g[a][i].first][g[a][i].second ^ value])
            dfs(g[a][i].first, g[a][i].second ^ value);
}

int main(void) {
    mainIO();
    int a, b, w;
    cin >> n >> m;
    g.resize(n + 1);
    
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    dfs(1, 0);

    if (ans == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
