#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 1000007
#define MOD 1000000007

long long dp[MAXN][2];

int main(void) {_
    int t, n;
    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;
    
    for (int i = 2; i <= 1e6; i++) {
        dp[i][0] = (dp[i - 1][1] + 2 * dp[i - 1][0]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }

    while(t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    return 0;
}
