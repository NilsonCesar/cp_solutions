#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, w;
vector<long long> W, V;
vector<vector<long long>> dp;

long long solve(int i, int ww) {
    // cout << i << ' ' << ww << '\n';
    if (i == n && ww >= 0) return 0;
    else if (i == n) return -1e8;
    if (dp[i][ww] != -1) return dp[i][ww];
    dp[i][ww] = solve(i + 1, ww);
    if (ww - W[i] >= 0)
        dp[i][ww] = max(dp[i][ww], V[i] + solve(i + 1, ww - W[i]));
    return dp[i][ww];
}

int main(void) {
    mainIO();
    cin >> n >> w;
    W.resize(n + 7, 0); V.resize(n + 7, 0);
    dp.resize(n + 7, vector<long long>(w + 7, -1));
    for (int i = 0; i < n; i++)
        cin >> W[i] >> V[i];
    cout << solve(0, w) << '\n';

    return 0;
}
