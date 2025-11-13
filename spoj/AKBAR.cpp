#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int t;
    cin >> t;

    while(t--) {
        int n, r, m, u, v, k, s;
        cin >> n >> r >> m;
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 0; i < r; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> soldier(m + 1, 0);
        queue<vector<int>> to_visit;
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < m; i++) {
            cin >> k >> s;
            if (s == 0) {
                visited[k] = true;
                continue;
            }
            soldier[i + 1] = s;
            to_visit.push({k, i + 1, 0});
        }
        while(!to_visit.empty()) {
            vector<int> v = to_visit.front();
            int city = v[0], sold = v[1], d = v[2];
            to_visit.pop();
            if (visited[city]) continue;
            if (d > soldier[sold]) continue;
            visited[city] = true;
            for (int c: g[city]) {
                if (visited[c]) continue;
                to_visit.push({c, sold, d + 1});
            }
        }
        bool all_visited = true;
        for (int i = 1; i <= n; i++) {
            // cout << visited[i] << '\n';
            if (!visited[i])
                all_visited = false;
        }
        cout << (all_visited ? "Yes" : "No") << '\n';
    }


    return 0;
}
