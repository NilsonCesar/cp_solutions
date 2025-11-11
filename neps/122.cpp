#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int h, l;
vector<vector<int>> grid, visited;

int dfs(int i, int j, int count = 1) {
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    if (i + 1 < h && grid[i + 1][j] == grid[i][j]) count = max(count, dfs(i + 1, j, count + 1));
    if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j]) count = max(count, dfs(i - 1, j, count + 1));
    if (j + 1 < l && grid[i][j + 1] == grid[i][j]) count = max(count, dfs(i, j + 1, count + 1));
    if (j - 1 >= 0 && grid[i][j - 1] == grid[i][j]) count = max(count, dfs(i, j - 1, count + 1));
    return count;
}

int main(void) {
    mainIO();
    cin >> h >> l;
    int ans = 1e6;
    grid.resize(h, vector<int>(l));
    visited.resize(h, vector<int>(l, false));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            if (visited[i][j]) continue;
            ans = min(ans, dfs(i, j));
        }
    }

    cout << ans << '\n';

    return 0;
}
