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
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>());
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    map<int, int> pos;
    pos[n] = -1;
    queue<pair<int, int>> to_visit;
    to_visit.push({1, 1});
    vector<bool> visited(n + 1, false);

    while(!to_visit.empty()) {
        pair<int, int> node = to_visit.front();
        to_visit.pop();
        if (visited[node.first]) continue;
        visited[node.first] = true;
        pos[node.first] = node.second;
        for (int w: grid[node.first]) {
            if (visited[w]) continue;
            to_visit.push({w, node.second + 1});
        }
    }

    if (pos[n] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    cout << pos[n] << '\n';
    ans.push_back(n);
    int node = n;

    while(pos[n] != (int) ans.size()) {
        for (int u: grid[node]) {
            if (pos[u] == pos[node] - 1) {
                ans.push_back(u);
                node = u;
                break;
            }
        }
    }

    for (int i = (int) ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';


    return 0;
}
