#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<vector<char>> grid(19, vector<char>(19, 'N'));

int solve(int i, int j) {
    int max_ans = 0;
    
    if (grid[i - 1][j + 1] == 'P' && grid[i - 2][j + 2] == '.') {
        grid[i - 1][j + 1] = '.';
        max_ans = max(max_ans, 1 + solve(i - 2, j + 2));
        grid[i - 1][j + 1] = 'P';
    }
    if (grid[i - 1][j - 1] == 'P' && grid[i - 2][j - 2] == '.') {
        grid[i - 1][j - 1] = '.';
        max_ans = max(max_ans, 1 + solve(i - 2, j - 2));
        grid[i - 1][j - 1] = 'P';
    }
    if (grid[i + 1][j - 1] == 'P' && grid[i + 2][j - 2] == '.') {
        grid[i + 1][j - 1] = '.';
        max_ans = max(max_ans, 1 + solve(i + 2, j - 2));
        grid[i + 1][j - 1] = 'P';
    }
    if (grid[i + 1][j + 1] == 'P' && grid[i + 2][j + 2] == '.') {
        grid[i + 1][j + 1] = '.';
        max_ans = max(max_ans, 1 + solve(i + 2, j + 2));
        grid[i + 1][j + 1] = 'P';
    }
    
    return max_ans;
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
                grid[i][j] = '.';
                ans = max(ans, solve(i, j));
                grid[i][j] = 'B';
                // cout << i << ' ' << j << ' ' << ans << '\n';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}