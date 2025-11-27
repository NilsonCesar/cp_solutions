#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000007

long long dp[MAXN][107];

int main(void) {_
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> x[i];

    if (x[1] != 0) dp[1][x[1]] = 1;
    else 
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (x[i] != 0) dp[i][x[i]] = (dp[i - 1][x[i] - 1] + dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
        else
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (dp[n][i] % MOD);

    cout << ans % MOD << '\n';

    return 0;
}
