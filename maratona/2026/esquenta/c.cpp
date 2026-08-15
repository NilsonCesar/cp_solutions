#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n, e;
vector<vector<pair<ll, ll>>> graph;
vector<ll> sp;
vector<bool> visited;

void Dijkstra(ll s) {
	pair<ll, ll> v;
	sp[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({sp[s], s});

	while(!pq.empty()) {
		v = pq.top();
		pq.pop();
		if(visited[v.second]) continue;
		visited[v.second] = true;
		for(pair<ll, ll> p : graph[v.second]) {
			if(sp[p.first] > v.first + p.second) {
				sp[p.first] = v.first + p.second;
				pq.push({sp[p.first], p.first});
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	
	ll u, v, w;
	cin >> n >> e;
	graph.resize(n+7);
	sp.resize(n+7, numeric_limits<ll>::max());
	visited.resize(n+7, false);

	for(ll i = 0; i < e; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
        graph[v].push_back({w, u});
	}

    for (ll i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
        for (ll j = 0; j < (ll) graph[i].size(); j++) {
            ll c = graph[i][j].first;
            graph[i][j].first = graph[i][j].second;
            graph[i][j].second = c;
        }
    }

	Dijkstra(1);

	cout << (sp[n] == numeric_limits<ll>::max() ? -1 : sp[n]) << '\n';

    return 0;
}