#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int l, c;
int x, y;
int ansx = -1, ansy = -1;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    bool has_mov = false;

    if (i + 1 < l && !visited[i + 1][j] && grid[i + 1][j] == 'H') {
        has_mov = true;
        dfs(i + 1, j);
    }

    if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 'H') {
        has_mov = true;
        dfs(i - 1, j);
    }

    if (j + 1 < c && !visited[i][j + 1] && grid[i][j + 1] == 'H') {
        has_mov = true;
        dfs(i, j + 1);
    }

    if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 'H') {
        has_mov = true;
        dfs(i, j - 1);
    }

    if (!has_mov && ansx == -1 && ansy == -1) {
        ansx = i;
        ansy = j;
    }
}

int main(void) {
    mainIO();
    cin >> l >> c;
    grid.resize(l, vector<char>(c));
    visited.resize(l, vector<bool>(c, false));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                x = i; y = j;
            }
        }
    }

    dfs(x, y);

    cout << ansx + 1 << ' ' << ansy + 1 << '\n';
    
    return 0;
}
