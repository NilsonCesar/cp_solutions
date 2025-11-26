#include <bits/stdc++.h>
 
using namespace std;
 
#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
int dp[MAXN];
 
int main(void) {_
    int n, x, h_sum = 0, s_sum = 0;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) {cin >> h[i]; h_sum += h[i];}
    for (int i = 0; i < n; i++) {cin >> s[i]; s_sum += s[i];}
 
    if (h_sum <= x) {
        cout << s_sum << '\n';
        return 0;
    }
 
    for (int i = 0; i < n; i++) {
        // cout << "SUM: " << sum << '\n';
        for(int sum = x; sum >= h[i]; sum--) {
            if (sum - h[i] < 0) continue;
            // cout << "i: " << i << " " << sum - h[i] << ' ' << dp[sum - h[i]] << '\n';
            dp[sum] = max(dp[sum], dp[sum - h[i]] + s[i]);
        }
        // cout << "dp[" << sum << "] = " << dp[sum] << '\n'; 
        // cout << '\n';
    }

    cout << '\n';

    cout << dp[x] << '\n';
 
    return 0;
}