#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<char>> grid;
int n, m, x, y;

void dfs(int i, int j) {
    if (i + 1 < n && grid[i + 1][j] == '.') {
        grid[i + 1][j] = 'o';
        dfs(i + 1, j);
    } else if (i + 1 < n && grid[i + 1][j] == '#') {
        if (j - 1 >= 0 && grid[i][j - 1] == '.') {
            grid[i][j - 1] = 'o';
            dfs(i, j - 1);
        }
        if (j + 1 < m && grid[i][j + 1] == '.') {
            grid[i][j + 1] = 'o';
            dfs(i, j + 1);
        }
    }
    
}


int main(void) {
    mainIO();
    cin >> n >> m;
    grid.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                x = i; y = j;
            }
        }
    }

    dfs(x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}