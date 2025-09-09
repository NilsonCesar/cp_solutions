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
vector<vector<int>> g;
long long memo[500010];

long long dp(int u) {
    if (memo[u] != -1) return memo[u];
    if ((int) g[u].size() == 0) return 0;
    memo[u] = 0;
    for (int v : g[u]) {
        memo[u] = max(memo[u], dp(v) + 1);
    }
    return memo[u];
}

int main(void) {
    mainIO();
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    g.resize(n + 7, vector<int>());
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp(i));
    }

    cout << ans << '\n';

    return 0;
}
