#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, m;
vector<vector<char>> g;

int main(void) {_
    cin >> n >> m;
    g.resize(n, vector<char>(m));
    vector<vector<int>> monsters, visited(n, vector<int>(m, false));
    vector<vector<char>> moves(n, vector<char>(m, '0'));
    int ax, ay, endx, endy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'M') {
                monsters.push_back({i, j});
                visited[i][j] = true;
            } else if (g[i][j] == '#') {
                visited[i][j] = true;
            } else if (g[i][j] == 'A') {
                visited[i][j] = true;
                ax = i;
                ay = j;
            }
        }
    }

    queue<vector<int>> q;
    for (vector<int> monster: monsters) {
        q.push({monster[0], monster[1], 0});
    }
    q.push({ax, ay, 1});
    bool found = false;

    while(!q.empty()) {
        vector<int> node = q.front();
        int x = node[0];
        int y = node[1];
        int flag = node[2];
        q.pop();

        if ((x == n - 1 || y == m - 1 || x == 0 || y == 0) && flag) {
            endx = x;
            endy = y;
            found = true;
            break;
        }

        if (x - 1 >= 0 && !visited[x - 1][y]) {
            visited[x - 1][y] = true;
            if (flag) {
                moves[x - 1][y] = 'U';
            }
            q.push({x - 1, y, flag});
        }

        if (x + 1 < n && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            if (flag) {
                moves[x + 1][y] = 'D';
            }
            q.push({x + 1, y, flag});
        }

        if (y - 1 >= 0 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            if (flag) {
                moves[x][y - 1] = 'L';
            }
            q.push({x, y - 1, flag});
        }

        if (y + 1 < m && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            if (flag) {
                moves[x][y + 1] = 'R';
            }
            q.push({x, y + 1, flag});
        }
    }
    
    if (!found) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    string path = "";

    int x = endx, y = endy;

    while (x != ax || y != ay) {
        char m = moves[x][y];
        path += m;
        if (m == 'D') {
            x--;
        } else if (m == 'U') {
            x++;
        } else if (m == 'L') {
            y++;
        } else {
            y--;
        }
    }

    reverse(path.begin(), path.end());

    cout << (int) path.size() << '\n';
    cout << path << '\n';

    return 0;
}
