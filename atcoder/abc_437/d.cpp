#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 998244353

int main(void) {_
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1, 0), b(m + 1, 0), prefb(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) { cin >> b[j]; }
    sort(b.begin(), b.end());
    for (int j = 1; j <= m; j++)
        prefb[j] = prefb[j - 1] + b[j];
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        auto k_p = upper_bound(b.begin(), b.end(), a[i]);
        int k = distance(b.begin(), k_p);
        k--;
        // cout << k << '\n';
        long long sl = prefb[k], sg = prefb[m] - prefb[k];
        ans += (k * a[i] - sl + sg - (m - k) * a[i]) % MOD;
    }

    cout << ans % MOD << '\n';

    return 0;
}
