#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

struct s
{
    int x, y;
    int step;
    int dir;
};


vector<int> dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};

int main(void) {
    mainIO();
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(505, vector<char>(505));
    vector<vector<vector<int>>> dp(505, vector<vector<int>>(505, vector<int>(2, 1e8)));
    queue<s> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                dp[i][j][0] = 0;
                q.push({i, j, 0, 0});
            }
        }
    }

    while(!q.empty()) {
        s a = q.front();
        q.pop();
        if (a.step > dp[a.x][a.y][a.dir]) continue;
        if (grid[a.x][a.y] == 'G') {
            cout << a.step << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (grid[nx][ny] == '#') continue;
            if (grid[nx][ny] == 'x' && a.dir == 0) continue;
            if (grid[nx][ny] == 'o' && a.dir == 1) continue;
            int nstep = a.step + 1;
            int ndir = (a.dir + (grid[nx][ny] == '?')) % 2;
            if (nstep < dp[nx][ny][ndir]) {
                dp[nx][ny][ndir] = nstep;
                q.push({nx, ny, nstep, ndir});
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}
