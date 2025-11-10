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
    int n, m, init_x, init_y, end_x, end_y;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                init_x = i;
                init_y = j;
            }
            if (grid[i][j] == 3) {
                end_x = i;
                end_y = j;
            }
        }
    }

    map<pair<int, int>, bool> visited;
    queue<vector<int>> to_visit;
    to_visit.push({init_x, init_y, 1});

    while(!to_visit.empty()) {
        vector<int> node = to_visit.front();
        to_visit.pop();
        if (visited[{node[0], node[1]}]) continue;
        visited[{node[0], node[1]}] = true;
        if (node[0] + 1 < n) {
            if (grid[node[0] + 1][node[1]] == 3) {
                cout << node[2] + 1 << '\n';
                return 0;
            } else if (grid[node[0] + 1][node[1]] == 1) {
                to_visit.push({node[0] + 1, node[1], node[2] + 1});
            }
        }

        if (node[0] - 1 >= 0) {
            if (grid[node[0] - 1][node[1]] == 3) {
                cout << node[2] + 1 << '\n';
                return 0;
            } else if (grid[node[0] - 1][node[1]] == 1) {
                to_visit.push({node[0] - 1, node[1], node[2] + 1});
            }
        }

        if (node[1] + 1 < m) {
            if (grid[node[0]][node[1] + 1] == 3) {
                cout << node[2] + 1 << '\n';
                return 0;
            } else if (grid[node[0]][node[1] + 1] == 1) {
                to_visit.push({node[0], node[1] + 1, node[2] + 1});
            }
        }

        if (node[1] - 1 >= 0) {
            if (grid[node[0]][node[1] - 1] == 3) {
                cout << node[2] + 1 << '\n';
                return 0;
            } else if (grid[node[0]][node[1] - 1] == 1) {
                to_visit.push({node[0], node[1] - 1, node[2] + 1});
            }
        }
    }

    return 0;
}
