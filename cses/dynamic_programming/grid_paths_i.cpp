#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000007

int n;
vector<vector<char>> grid;
vector<vector<long long>> memo;
long long ans;


long long solve(int i, int j) {
    if (grid[i][j] == '*') {
        memo[i][j] = -1;
        return 0;
    }
    if (i == n - 1 && j == n - 1) {
        ans++;
        memo[i][j] = 1;
        return 1;
    }
    if (memo[i][j]) {
        return (memo[i][j] == -1 ? 0 : memo[i][j]) % MOD;
    }
    

    int paths = 0;
    if (i + 1 < n) paths += (solve(i + 1, j) % MOD);
    if (j + 1 < n) paths += (solve(i, j + 1) % MOD);
    memo[i][j] = paths;
    if (memo[i][j] == 0) {
        memo[i][j] = -1;
    }

    return (memo[i][j] == -1 ? 0 : memo[i][j]) % MOD;
}

int main(void) {_
    cin >> n;
    grid.resize(n, vector<char>(n));
    memo.resize(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << solve(0, 0) << '\n';
    return 0;
}
