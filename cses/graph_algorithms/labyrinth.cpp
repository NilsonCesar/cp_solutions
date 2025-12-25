#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, m, found = 0, sourcex, sourcey, endx, endy;
vector<vector<char>> g;

int main(void) {_
    cin >> n >> m;
    g.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                sourcex = i;
                sourcey = j;
            }
            if (g[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    // cout << sourcex << ' ' << sourcey << '\n';
    // cout << endx << ' ' << endy << '\n';

    int ans = 0;
    queue<vector<int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    char moves[n + 1][m + 1];
    q.push({sourcex, sourcey, 0});

    while(!q.empty()) {
        int x = q.front()[0], y = q.front()[1], d = q.front()[2];
        // cout << x << ' ' << y << ' ' << d << '\n';
        q.pop();
        if (g[x][y] == '#') continue;
        visited[x][y] = true;

        if (x == endx && y == endy) {
            found = 1;
            ans = d;
            break;
        }

        if (x + 1 < n && g[x + 1][y] != '#' && !visited[x + 1][y]) {
            q.push({x + 1, y, d + 1});
            moves[x + 1][y] = 'D';
            visited[x + 1][y] = true;
        }

        if (x - 1 >= 0 && g[x - 1][y] != '#' && !visited[x - 1][y]) {
            q.push({x - 1, y, d + 1});
            moves[x - 1][y] = 'U';
            visited[x - 1][y] = true;
        }

        if (y + 1 < m && g[x][y + 1] != '#' && !visited[x][y + 1]) {
            q.push({x, y + 1, d + 1});
            moves[x][y + 1] = 'R';
            visited[x][y + 1] = true;
        }

        if (y - 1 >= 0 && g[x][y - 1] != '#' && !visited[x][y - 1]) {
            q.push({x, y - 1, d + 1});
            moves[x][y - 1] = 'L';
            visited[x][y - 1] = true;
        }
    }

    if (!found) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    cout << ans << '\n';

    string path = "";
    int x = endx, y = endy;

    while(x != sourcex || y != sourcey) {
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

    for (char c: path)
        cout << c;
    cout << '\n';

    return 0;
}
