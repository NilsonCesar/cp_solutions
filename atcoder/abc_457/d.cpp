#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long l = 1, r = 2e18 + 7, ans;

    while (l <= r) {
        long long m = (l + r) / 2;
        long long kk = k;
        for (int i = 1; i <= n; i++) {
            if (a[i] < m) {
                kk -= (m - a[i] + i - 1) / i;
            }

            if (kk < 0) break;
        }

        if (kk >= 0) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
