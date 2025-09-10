#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define MAXN 5050

int main(void) {
    mainIO();
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> first_occur(MAXN, -1), last_occur(MAXN, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (first_occur[a[i]] == -1)
            first_occur[a[i]] = i;
        last_occur[a[i]] = i;
    }

    vector<long long> dp(n + 1, 0);

    vector<int> visted_timestamp(MAXN, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];

        long long sequence_xor = 0;
        int min_occur = i - 1;
        int max_occur = i - 1;

        for (int j = i - 1; j >= 0; j--) {
            int city = a[j];

            min_occur = min(min_occur, first_occur[city]);
            max_occur = max(max_occur, last_occur[city]);

            if (visted_timestamp[city] != i) {
                visted_timestamp[city] = i;
                sequence_xor ^= city;
            }

            if (min_occur == j && max_occur == i - 1) 
                dp[i] = max(dp[i], dp[j] + sequence_xor);
            
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
