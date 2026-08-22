#include <bits/stdc++.h>
using namespace std;

int n, l = 1;
vector<vector<int>> g, gr;
vector<int> scc;
vector<bool> visited;
stack<int> processing_order;

void dfsr(int v) {
	visited[v] = true;
	for(int i = 0; i < (int) gr[v].size(); i++) {
		if(!visited[gr[v][i]]) 
			dfsr(gr[v][i]);
	}
	processing_order.push(v);
}

void dfs(int v, int l) {
	scc[v] = l;
	for(int i = 0; i < (int) g[v].size(); i++)
		if(!scc[g[v][i]])
			dfs(g[v][i], l);
}

void Kosaraju_Sharir() {
	int v;
	for(int i = 1; i <= n; i++) 
		if(!visited[i])
			dfsr(i);

	while(!processing_order.empty()) {
		v = processing_order.top();
		processing_order.pop();
		if(!scc[v]) dfs(v, l++);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int m, u, v;
	cin >> n >> m;
	g.resize(n + 1);
	gr.resize(n + 1);
	scc.resize(n + 1, 0);
    vector<vector<int>> edges;
	visited.resize(n + 1, false);

	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		gr[v].push_back(u);
        edges.push_back({u, v});
	}

	Kosaraju_Sharir();

    int sin = 0, sout = 0;
    vector<int> in_degree(l + 1, 0), out_degree(l + 1, 0);
    for (int i = 0; i < m; i++) {
        if (scc[edges[i][0]] != scc[edges[i][1]]) {
            out_degree[scc[edges[i][0]]]++;
            in_degree[scc[edges[i][1]]]++;
        }
    }

    if (l == 2) {
        cout << 0 << '\n';
        return 0;
    }

	for(int i = 1; i <= l - 1; i++) {
        if (!in_degree[i]) sin++;
        if (!out_degree[i]) sout++;
    }
	cout << max(sin, sout) << '\n';

    return 0;
}