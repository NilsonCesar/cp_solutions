#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<vector<int>> dp(19, vector<int>(19, 0));
vector<vector<char>> grid(19, vector<char>(19, 'N'));
vector<vector<bool>> visited(19, vector<bool>(19, false));


int solve(int i, int j) {
    if (dp[i][j]) return dp[i][j];
    if (visited[i][j]) return 0;
    visited[i][j] = true;  
    vector<int> ans(4, 0);
    if (grid[i - 1][j + 1] == 'P' && grid[i - 2][j + 2] == '.' && !visited[i - 2][j + 2]) {
        ans[0] = 1 + solve(i - 2, j + 2);
    }
    if (grid[i - 1][j - 1] == 'P' && grid[i - 2][j - 2] == '.' && !visited[i - 2][j - 2]) {
        ans[1] = 1 + solve(i - 2, j - 2);
    }
    if (grid[i + 1][j - 1] == 'P' && grid[i + 2][j - 2] == '.' && !visited[i + 2][j - 2]) {
        ans[2] = 1 + solve(i + 2, j - 2);
    }
    if (grid[i + 1][j + 1] == 'P' && grid[i + 2][j + 2] == '.' && !visited[i + 2][j + 2]) {
        ans[3] = 1 + solve(i + 2, j + 2);
    }
    visited[i][j] = false;
    int anst = 0;
    for (int k = 0; k < 4; k++) anst = max(anst, ans[k]);
    dp[i][j] = anst;
    return anst;
}

int main(void) {_
    int n;
    cin >> n;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 2; j <= n + 1; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 2; j <= n + 1; j++) {
            if (grid[i][j] == 'B') {
                ans = max(ans, solve(i, j));
                // cout << i << ' ' << j << ' ' << ans << '\n';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}