#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<bool>> visited;
vector<vector<char>> grid;

int main(void) {
    mainIO();

    int n, m;
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, true));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = grid[i][j] != '#';
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                if (!(
                    i > 0 && grid[i - 1][j] == '#' &&
                    i < n - 1 && grid[i + 1][j] == '#' &&
                    j > 0 && grid[i][j - 1] == '#' &&
                    j < n - 1 && grid[i][j + 1] == '#')) {
                        ans++;
                    }
            }
        }
    }

    cout << ans << '\n';


    return 0;
}
