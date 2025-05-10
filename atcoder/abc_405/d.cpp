#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int h, w;
vector<vector<char>> grid(1002, vector<char>(1002, '#')), ans(1002, vector<char>(1002, '.'));
vector<vector<int>> d(1002, vector<int>(1002, -1));
vector<vector<bool>> visited;

int main(void) {
    mainIO();
    cin >> h >> w;
    queue<vector<int>> tiles;
    const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    const char mp[] = "<>^v";
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                tiles.push({i, j, 0});
                ans[i][j] = 'E';
                d[i][j] = 0;
            } else if (grid[i][j] == '#') ans[i][j] = '#';
        }

    while (!tiles.empty()) {
        vector<int> nextTile = tiles.front();
        tiles.pop();
        int i = nextTile[0];
        int j = nextTile[1];
        int actD = nextTile[2];

        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k], jj = j + dy[k];
            if (grid[ii][jj] == '#') continue;
            if (d[ii][jj] == -1) {
                d[ii][jj] = actD + 1;
                ans[ii][jj] = mp[k];
                tiles.push({ii, jj, actD});
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}