#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n1, n2, k1, k2;
long long memo[110][110][15][15];

long long dp(int n, int m, int k1p, int k2p) {
    if (k1p < 0 || k2p < 0) {
        return 0;
    }
    if (n == 0 && m == 0) {
        return memo[n][m][k1p][k2p] = 1;
    }
    if (memo[n][m][k1p][k2p] != -1) {
        return memo[n][m][k1p][k2p];
    }
    memo[n][m][k1p][k2p] = 0;
    if (n > 0 && k1p > 0) {
        memo[n - 1][m][k1p - 1][k2] = dp(n - 1, m, k1p - 1, k2);
    }
    if (m > 0 && k2p > 0) {
        memo[n][m - 1][k1][k2p - 1] = dp(n, m - 1, k1, k2p - 1);
    }
    if (n > 0 && m > 0 && k1p > 0 && k2p > 0) {
        memo[n][m][k1p][k2p] = memo[n][m - 1][k1][k2p - 1] + memo[n - 1][m][k1p - 1][k2];
    }
    else if (n > 0 && k1p > 0) memo[n][m][k1p][k2p] =  memo[n - 1][m][k1p - 1][k2];
    else if (m > 0 && k2p > 0) memo[n][m][k1p][k2p] = memo[n][m - 1][k1][k2p - 1];
    return memo[n][m][k1p][k2p] % 100000000;
}

int main(void) {
    mainIO();
    cin >> n1 >> n2 >> k1 >> k2;
    memset(memo, -1, sizeof(memo));
    cout << dp(n1, n2, k1, k2) % 100000000 << '\n';

    return 0;
}
