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
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    grid[0][0] = 0;
    queue<vector<int>> pos;
    pos.push({0, 0});
    while(!pos.empty()) {
        vector<int> cur_pos = pos.front();
        pos.pop();
        for (int s1 = 0; s1 < 2; s1++) {
            for (int s2 = 0; s2 < 2; s2++) {
                for (int p = 0; p < 2; p++) {
                    int i = cur_pos[0] + (!s1 ? 1 : -1) * (!p ? 1 : 2);
                    int j = cur_pos[1] + (!s2 ? 1 : -1) * (!p ? 2 : 1);
                    if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == -1) {
                        grid[i][j] = 1 + grid[cur_pos[0]][cur_pos[1]];
                        pos.push({i, j});
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
