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
    int n, m, h;
    cin >> n >> h >> m;
    vector<int> a(n + 1), b(n + 1), sumb(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sumb[i] = b[i] + sumb[i - 1];
    }
    
    int ans = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = a[i]; j <= h; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
        }

        if (sumb[i] - dp[i][h] > m) {
            ans = i - 1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
