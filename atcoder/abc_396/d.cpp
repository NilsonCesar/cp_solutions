#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<unsigned long long>> g;
vector<bool> visited;
unsigned long long ans = -1;
int n;

void solve(int u, unsigned long long act_xor, vector<bool> visited, int label = 0) {
    // cout << "label: " << label << " Node: " << u << " Act xor: " << act_xor << '\n';
    if(u == n) {
	if(ans == -1) ans = act_xor;
	ans = min(ans, act_xor);
	return;
    }
    for(int i = 2; i <= n; i++) {
	if(visited[i] || g[u][i] == -1) continue;
	if(u == 1) label++;
    	visited[i] = true;
	solve(i, act_xor ^ g[u][i], visited, label);
	visited[i] = false;
    }
}

int main(void) {
    // mainIO();
    int m, u, v;
    unsigned long long w;
    cin >> n >> m;
    g.resize(n + 1, vector<unsigned long long>(n + 1, -1));
    visited.resize(n + 1, false);
    for(int i = 0; i < m; i++) {
	cin >> u >> v >> w;
	g[u][v] = w;
	g[v][u] = w;
    }
    solve(1, 0, visited);
    cout << ans << '\n';
    return 0;
}
