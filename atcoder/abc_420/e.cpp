#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

struct disjoint_set {
    vector<int> ancestor;
    vector<int> rank;

    disjoint_set(int n) {
        ancestor.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            ancestor[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (ancestor[u] == u) return u;
        else return ancestor[u] = find(ancestor[u]);
    }

    void une(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            ancestor[u] = v;
            rank[v] += rank[u];
        } else {
            ancestor[v] = u;
            rank[u] += rank[v];
        }
    }

};

int main(void) {
    mainIO();
    int n, q, t, u, v;
    vector<bool> black;

    cin >> n >> q;
    black.resize(n + 7, false);
    disjoint_set dsu(n + 7);

    while(q--) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            dsu.une(u, v);
        } else if (t == 2) {
            cin >> v;
            if (black[v]) {
                dsu.rank[dsu.find(v)]--;
                black[v] = false;
            } else {
                dsu.rank[dsu.find(v)]++;
                black[v] = true;
            } 
        } else {
            cin >> v;
            if (dsu.rank[dsu.find(v)] > 0) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            cout << '\n';
        }
    }

    return 0;
}
