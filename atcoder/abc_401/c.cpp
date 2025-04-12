#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, k;
vector<unsigned long long> memo(1e6 + 7, 1);

int main(void) {
    mainIO();
    cin >> n >> k;
    long long diff = k, mod = 1e9;

    for (int j = k; j <= n; j++) {
        memo[j] = diff;
        diff = (((diff + memo[j]) % mod) - memo[j- k] + mod) % mod;
    }
    cout << memo[n] << '\n';
    return 0;
}