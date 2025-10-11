#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int ans = 1e9, n, m;
vector<vector<int>> edges;
vector<int> group;

void check_groups() {
    int acc = 0;
    for (int i = 0; i < m; i++) {
        acc += group[edges[i][0]] == group[edges[i][1]];
    }
    ans = min(ans, acc);
}

void find_groups(int i) {
    if (i == n) {
        check_groups();
        return;
    }
    group[i] = 0;
    find_groups(i + 1);
    group[i] = 1;
    find_groups(i + 1);
}

int main(void) {
    mainIO();
    int u, v;
    cin >> n >> m;
    group.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges.push_back({u, v});
    }

    find_groups(1);

    cout << ans << '\n';

    return 0;
}
