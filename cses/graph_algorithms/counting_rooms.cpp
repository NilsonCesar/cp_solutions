#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m;
vector<vector<bool>> visited;
vector<vector<char>> grid;

void floodfill(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '#' || visited[r][c]) return;
    visited[r][c] = true;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main(void) {
    mainIO();
    int ans = 0;
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, true));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '.') visited[i][j] = false;
        }
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j]) {
                ans++;
                floodfill(i, j);
            }

    cout << ans << '\n';

    return 0;
}
