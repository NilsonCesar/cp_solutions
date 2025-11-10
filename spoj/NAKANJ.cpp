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
    vector<int> sh = {1, 2}, sig = {-1, 1};

    while(t--) {
        vector<vector<int>> grid(8, vector<int>(8, 0));
        string a, b;
        bool done = false;
        cin >> a >> b;
        int i = a[0] - 'a', j = a[1] - '1', k = b[0] - 'a', l = b[1] - '1';
        // cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
        // if (i == k && j == l) {
        //     cout << 0 << '\n';
        //     break;
        // }
        vector<vector<bool>> visited(8, vector<bool>(8, false));
        queue<vector<int>> pos;
        pos.push({i, j});
        while(!pos.empty()) {
            vector<int> node = pos.front();
            pos.pop();
            if (visited[node[0]][node[1]]) continue;
            visited[node[0]][node[1]] = true;

            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    for (int e = 0; e < 2; e++) {
                        int f = !d;
                        int sx = node[0] + sig[c] * sh[d];
                        int sy = node[1] + sig[e] * sh[f];

                        if (sx >= 0 && sx < 8 && sy >= 0 && sy < 8 && !visited[sx][sy]) {
                            grid[sx][sy] = grid[node[0]][node[1]] + 1;
                            pos.push({sx, sy});
                        }

                        if (sx == k && sy == l) {
                            cout << grid[sx][sy] << '\n';
                            done = true;
                            break;
                        }
                    }

                    if (done) break;
                }

                if (done) break;
            }
            
            if (done) break;
        }
    
        // for (int i = 0; i < 8; i++) {
        //     for (int j = 0; j < 8; j++) {
        //         cout << grid[i][j];
        //     }
        //     cout << '\n';
        // }
    }

    return 0;
}
