#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, qq;
    cin >> n >> m;
    vector<vector<int>> ga(m + 1, vector<int>()), gm(n + 1, vector<int>());

    for (int i = 0; i < n; i++) {
        int qm, a;
        cin >> qm;
        for (int j = 0; j < qm; j++) {
            cin >> a;
            ga[a].push_back(i + 1);
            gm[i + 1].push_back(a);
        }
    }
    
    cin >> qq;
    map<pair<int, int>, pair<int, int>> p;
    while(qq--) {
        int x, y;
        cin >> x >> y;
        map<pair<int, int>, bool> visited;
        bool found = false;
        queue<pair<int, int>> q;
        q.push({x, 0});
        while(!q.empty()) {
            pair<int, int> node = q.front();
            // cout << node.first << ' ' << node.second << '\n';
            q.pop();
            if (visited.find(node) != visited.end()) continue;
            visited[node] = true;
            if (node.first == y) {
                found = true;
                break;
            }

            if (node.second) {
                for (int actor: gm[node.first]) {
                    if (visited.find({actor, 0}) != visited.end()) continue;
                    p[{actor, 0}] = node;
                    q.push({actor, 0});
                }
            } else {
                for (int movie: ga[node.first]) {
                    if (visited.find({movie, 1}) != visited.end()) continue;
                    p[{movie, 1}] = node;
                    q.push({movie, 1});
                }
            }
        }

        if (found) {
            vector<int> ans;
            pair<int, int> root = {y, 0};
            int d = 0;
            while (root.first != x || root.second == 1) {
                // cout << root.first << ' ' << root.second << '\n';
                ans.push_back(root.first);
                root = p[root];
                d += !root.second;
            }
            d++;
            ans.push_back(x);
            cout << d << '\n';
            for (int i = -1 + (int) ans.size(); i >= 0; i--) cout << ans[i] << ' ';
        }
        else cout << -1;
        cout << '\n';
    }


    return 0;
}