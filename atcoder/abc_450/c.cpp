#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, m;
bool border;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int i, int j) {
    border = border || (i == 0 || i == n - 1 || j == 0 || j == m - 1);
    visited[i][j] = true;
    if (i - 1 >= 0 && !visited[i - 1][j]) dfs(i - 1, j);
    if (i + 1 < n && !visited[i + 1][j]) dfs(i + 1, j);
    if (j - 1 >= 0 && !visited[i][j - 1]) dfs(i, j - 1);
    if (j + 1 < m && !visited[i][j + 1]) dfs(i, j + 1);
}

int main(void) {_
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') visited[i][j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            border = i == 0 || i == n - 1 || j == 0 || j == m - 1;
            dfs(i, j);
            if (!border) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
