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
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> shelves(n);
    vector<vector<int>> sumpref(n, vector<int>(105, 0));
    vector<vector<int>> dp(105, vector<int>(1e5 + 5, 0));
    vector<vector<int>> max_value(105, vector<int>(1e5 + 5, 0));
    

    for (int i = 0; i < n; i++) {
        cin >> q;
        shelves[i].resize(q);
        for (int j = 0; j < q; j++) {
            cin >> shelves[i][j];
            sumpref[i][j + 1] += sumpref[i][j] + shelves[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int s_len = (int) shelves[i].size();
        for (int k = 0; k <= min(m, s_len); k++) {
            for (int j = 0; j <= k; j++) {
                max_value[i][k] = max(max_value[i][k], sumpref[i][j] + sumpref[i][s_len] - sumpref[i][s_len - k + j]);
            }
        }
    }

    for (int k = 0; k <= m; k++) 
        dp[1][k] = max_value[0][k];
    
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= min(j, (int) shelves[i - 1].size()); k++) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + max_value[i - 1][k]);
    cout << dp[n][m] << '\n';

    return 0;
}
