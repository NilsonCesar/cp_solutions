#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios_base::sync_with_stdio(0);

int id = 2, monarchy = 1;
vector<bool> searched(1e5+7, false), dead(1e5+7, false), parent(1e5+7);
vector<vector<int>> g;

void foundMonarchy(int u) {
    if (searched[u]) {
        return foundMonarchy(parent[u]);
    }
    if (!dead[u]) {
        monarchy = u;
        return;
    }
    for (int v : g[u]) {
        if (!dead[monarchy]) return;
        if (searched[v]) continue;
        foundMonarchy(v);
    }
    if (dead[monarchy]) {
        searched[u] = true;
        foundMonarchy(parent[u]);
    }
}

int main() {_
    int q, t, x;
    cin >> q;
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    parent[1] = 1;

    while(q--) {
        cin >> t >> x;
        if (t == 1) {
            g[x].push_back(id);
            parent[id] = x;
            g.push_back(vector<int>());
            id++;
        } else {
            dead[x] = true;
            foundMonarchy(monarchy);
            cout << monarchy << '\n';
        }
    }

    return 0;
}