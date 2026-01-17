#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007


struct DSU {
    vector<int> parent;
    vector<int> edges;
    vector<int> nodes;

    DSU(int n) {
        parent.resize(n);
        edges.resize(n, 0);
        nodes.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    } 

    void merge(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        if (pi == pj) edges[pi]++;
        else if (nodes[pi] > nodes[pj] ) {
            parent[pj] = pi;
            nodes[pi] += nodes[pj];
            edges[pi] += edges[pj] + 1; 
        } else {
            parent[pi] = pj;
            nodes[pj] += nodes[pi];
            edges[pj] += edges[pi] + 1;
        }
    }
};

int main(void) {_
    int n;
    long long x, r;
    cin >> n;
    
    vector<pair<long long, long long>> rabbits(n);
    map<long long, int> coords;
    int id_counter = 0;

    auto get_id = [&](long long x) {
        if (coords.find(x) == coords.end()) {
            coords[x] = id_counter++;
        }
        return coords[x];
    };

    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) {
        cin >> x >> r;
        int u = get_id(x - r);
        int v = get_id(x + r);
        edges.push_back({u, v});
    }

    DSU dsu(id_counter);

    for (auto e : edges) {
        dsu.merge(e.first, e.second);
    }

    int ans = 0;
    vector<bool> visited(id_counter, false);

    for (int i = 0; i < id_counter; i++) {
        int p = dsu.find(i);
        if (!visited[p]) {
            visited[p] = true;
            ans += min(dsu.edges[p], dsu.nodes[p]);
        }
    }

    cout << ans << '\n';

    return 0;
}
