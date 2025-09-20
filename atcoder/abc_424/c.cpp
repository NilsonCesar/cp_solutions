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
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> learned;

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        if (u == 0 && v == 0) {
            learned.push_back(i + 1);
        } else {
            if (u != i + 1) g[u].push_back(i + 1);
            if (v != i + 1 && v != u) g[v].push_back(i + 1);
        }
    }

    int ans = 0;
    vector<bool> visited(n + 7, false);

    while((int) learned.size()) {
        int tail = learned[-1 + (int) learned.size()];
        learned.pop_back();
        if (visited[tail]) continue;
        visited[tail] = true;
        ans++;
        for (int i = 0; i < (int) g[tail].size(); i++)
            learned.push_back(g[tail][i]);
    }

    cout << ans << '\n';

    return 0;
}
