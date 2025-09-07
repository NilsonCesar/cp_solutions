#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    vector<long long> dp(n + 1, 0);

    for (int i = c0; i <= n; i++)
        dp[i] = (i / c0)  * d0;
    
    for (int i = c0; i <= n; i++)
        dp[i] = max(dp[i], dp[i - c0] + d0);

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int k_max = a / b;
        for (int j = n; j >= 0; j--) {
            for (int k = 1; k <= k_max; k++) {
                long long k_custo = k * c;
                long long k_lucro = k * d;

                if (j >= k_custo) {
                    dp[j] = max(dp[j], dp[j - k_custo] + k_lucro);
                } else break;
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
