#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> g;
vector<int> distA, distB;

int main(void) {
    mainIO();
    int n, u, v, a, b;
    cin >> n;
    distA.resize(n + 1);
    distB.resize(n + 1);
    g.resize(n + 1, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int maxDist = 0;
    queue<vector<int>> q;
    q.push({1, 0});
    vector<bool> visited(n + 1, false);

    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        if (visited[node[0]]) continue;
        visited[node[0]] = true;
        if (node[1] > maxDist) {
            maxDist = node[1];
            a = node[0];
        } else if (node[1] == maxDist) a = max(a, node[0]);
        for (int i = 0; i < (int) g[node[0]].size(); i++) {
            q.push({g[node[0]][i], node[1] + 1});
        }
    }

    q.push({a, 0});
    visited.clear();
    visited.resize(n + 1, false);
    maxDist = 0;

    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        if (visited[node[0]]) continue;
        visited[node[0]] = true;
        if (node[1] > maxDist) {
            maxDist = node[1];
            b = node[0];
        } else if (node[1] == maxDist) b = max(b, node[0]);
        for (int i = 0; i < (int) g[node[0]].size(); i++) {
            q.push({g[node[0]][i], node[1] + 1});
        }
    }

    q.push({a, 0});
    visited.clear();
    visited.resize(n + 1, false);
    maxDist = 0;
    
    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        if (visited[node[0]]) continue;
        distA[node[0]] = node[1];
        visited[node[0]] = true;
        for (int i = 0; i < (int) g[node[0]].size(); i++) {
            q.push({g[node[0]][i], node[1] + 1});
        }
    }

    q.push({b, 0});
    visited.clear();
    visited.resize(n + 1, false);
    maxDist = 0;
    
    while(!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        if (visited[node[0]]) continue;
        distB[node[0]] = node[1];
        visited[node[0]] = true;
        for (int i = 0; i < (int) g[node[0]].size(); i++) {
            q.push({g[node[0]][i], node[1] + 1});
        }
    }

    for (int i = 1; i <= n; i++) {
        if (distA[i] > distB[i]) {
            cout << a;
        } else if (distA[i] < distB[i]) {
            cout << b;
        } else if (a < b) {
            cout << b;
        } else {
            cout << a;
        }
        cout << '\n';
    }


    return 0;
}
