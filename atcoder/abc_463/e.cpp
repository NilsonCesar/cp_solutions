#include <bits/stdc++.h>
using namespace std;

long long n, e, y;
vector<vector<pair<long long, long long>>> graph;
vector<long long> sp;
vector<bool> visited;

void Dijkstra(long long s) {
	pair<long long, long long> v;
	sp[s] = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push({sp[s], s});

	while(!pq.empty()) {
		v = pq.top();
		pq.pop();
		if(visited[v.second]) continue;
		visited[v.second] = true;
		for(pair<long long, long long> p : graph[v.second]) {
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
	
	long long u, v, w;
	cin >> n >> e >> y;
	graph.resize(n + 1);
	sp.resize(n + 1, numeric_limits<long long>::max());
	visited.resize(n + 1, false);
    long long xw;

	for(long long i = 0; i < e; i++) {
		cin >> u >> v >> w;
        u--; v--;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

    for (long long i = 0; i < n; i++) {
        cin >> xw;
        graph[i].push_back({n, xw + y});
        graph[n].push_back({i, xw});
    }

	Dijkstra(0);

    for (int i = 1; i < n; i++) {
        cout << sp[i] << ' ';
    }
    cout << '\n';

    return 0;
}