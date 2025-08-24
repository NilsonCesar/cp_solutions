#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m, is, js, ig, jg, ans = 1e8;
vector<int> dirX = {0, 0, 1, -1}, dirY = {1, -1, 0, 0};
vector<vector<char>> grid;
vector<vector<bool>> visited;

void fillGrid(int i, int j, int par, int tmpAns) {
    cout << i << ' ' << j << ' ' << par << ' ' << tmpAns << '\n';
    if (tmpAns >= ans) return;
    if (grid[i][j] == 'G') {
        ans = min(ans, tmpAns);
        return;
    }
    for (int d = 0; d < 4; d++) {
        int ni = i + dirX[d], nj = j + dirY[d];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            if (grid[ni][nj] == '#') continue;
            else if (grid[ni][nj] == 'o' || grid[ni][nj] == 'x') {
                if (par % 2 == 0 && grid[ni][nj] == 'o') {
                    fillGrid(ni, nj, par, tmpAns + 1);
                } else if (grid[ni][nj] == 'x') {
                    fillGrid(ni, nj, par, tmpAns + 1);
                }
            } else if (grid[ni][nj] == '?') {
                visited[i][j] = false;
                fillGrid(ni, nj, par + 1, tmpAns + 1);
                visited[i][j] = true;
            } else {
                fillGrid(ni, nj, par, tmpAns + 1);
            }
        }
    }
    visited[i][j] = false;
}


int main(void) {
    mainIO();
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                is = i;
                js = j;
            } else if (grid[i][j] == 'G') {
                ig = i;
                jg = j;
            }
        }
    }
    fillGrid(is, js, 0, 0);

    cout << ans << '\n';

    return 0;
}
