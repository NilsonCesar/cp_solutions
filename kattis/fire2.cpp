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
    // mainIO();
    int t;
    cin >> t;

    while(t--) {
        int w, h, px, py;
        cin >> h >> w;
        vector<vector<char>> grid(w, vector<char>(h));
        vector<vector<int>> grid_p(w, vector<int>(h, 1e7)), grid_f(w, vector<int>(h, 1e7));
        queue<vector<int>> fires_to_visit;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> grid[i][j];

                if (grid[i][j] == '@') {
                    px = i;
                    py = j;
                }

                if (grid[i][j] == '*') {
                    fires_to_visit.push({i, j, 0});
                }
            }
        }

        while(!fires_to_visit.empty()) {
            vector<int> fire = fires_to_visit.front();
            int x = fire[0], y = fire[1], d = fire[2];
            fires_to_visit.pop(); 

            if (grid_f[x][y] != 1e7) continue;
            grid_f[x][y] = d;

            if (x + 1 < w && grid[x + 1][y] != '#') {
                fires_to_visit.push({x + 1, y, d + 1});
            }

            if (x - 1 >= 0 && grid[x - 1][y] != '#') {
                fires_to_visit.push({x - 1, y, d + 1});
            }

            if (y + 1 < h && grid[x][y + 1] != '#') {
                fires_to_visit.push({x, y + 1, d + 1});
            }

            if (y - 1 >= 0 && grid[x][y - 1] != '#') {
                fires_to_visit.push({x, y - 1, d + 1});
            }
        }

        // for (int i = 0; i < w; i++) {
        //     for (int j = 0; j < h; j++) {
        //         cout << grid_f[i][j];
        //     }
        //     cout << '\n';
        // }

        vector<vector<bool>> visited_p(w, vector<bool>(h, false));
        queue<vector<int>> to_visit;
        to_visit.push({px, py, 0});
        int ans = -1;

        while(!to_visit.empty()) {
            vector<int> point = to_visit.front();
            int x = point[0], y = point[1], d = point[2];
            to_visit.pop();

            if (grid_p[x][y] != 1e7) continue;
            grid_p[x][y] = d;

            if ((x == 0 || x == w - 1 || y == 0 || y == h - 1) && d <= grid_f[x][y]) {
                ans = d + 1;
                break;
            }

            if (x + 1 < w && grid[x + 1][y] != '#' && grid_p[x + 1][y] == 1e7 && d + 1 < grid_f[x + 1][y]) {
                to_visit.push({x + 1, y, d + 1});
            }

            if (x - 1 >= 0 && grid[x - 1][y] != '#' && grid_p[x - 1][y] == 1e7 && d + 1 < grid_f[x - 1][y]) {
                to_visit.push({x - 1, y, d + 1});
            }

            if (y + 1 < h && grid[x][y + 1] != '#' && grid_p[x][y + 1] == 1e7 && d + 1 < grid_f[x][y + 1]) {
                to_visit.push({x, y + 1, d + 1});
            }

            if (y - 1 >= 0 && grid[x][y - 1] != '#' && grid_p[x][y - 1] == 1e7 && d + 1 < grid_f[x][y - 1]) {
                to_visit.push({x, y - 1, d + 1});
            }
        }
        
        if (ans == -1) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << '\n';
    }


    return 0;
}
