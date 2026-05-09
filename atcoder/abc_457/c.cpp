#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, k, l;
    cin >> n >> k;
    vector<vector<long long>> a(n);
    vector<long long> c(n);

    for (long long i = 0; i < n; i++) {
        cin >> l;
        a[i].resize(l);
        for (long long j = 0; j < l; j++) cin >> a[i][j];
    }

    long long idx = 0;
    long long k_copy = k;

    for (long long i = 0; i < n; i++) {
        cin >> c[i];
        k_copy -= (c[i] * ((long long) a[i].size()));
        if (k_copy > 0) {
            k -= (c[i] * ((long long) a[i].size()));
            idx++;
        }
        // cout << k << '\n';
    }
    // cout << idx << '\n';

    k %= ((int) a[idx].size());

    cout << (k == 0 ? a[idx][(long long) a[idx].size() - 1] : a[idx][k - 1]) << '\n';

    return 0;
}
