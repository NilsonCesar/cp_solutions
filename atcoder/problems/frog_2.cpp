#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<long long> dp, stones;
int n, k;


long long ans(int i) {
    if (i == n - 1) return 0;
    for (int j = i + 1; j <= i + k; j++) {
        if (j >= n) break;
        if (dp[j] != 1e13) dp[i] = min(dp[i], dp[j] + abs(stones[j] - stones[i]));
        else dp[i] = min(dp[i], abs(stones[j] - stones[i]) + ans(j));
    }
    return dp[i];
}

int main(void) {
    mainIO();
    cin >> n >> k;
    dp.resize(n + 7, 1e13);
    stones.resize(n + 7, 1e13);

    for (int i = 0; i < n; i++)
        cin >> stones[i];

    cout << ans(0) << '\n';
    return 0;
}
