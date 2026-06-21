#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void solve(int t) {
    int n, q, l, r;
    char op;
    int f = 1;

    cin >> n >> q;
    vector<long long> candies(n + 1), a_alt(n + 1), prefsum(n + 1, 0), multsum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> candies[i];
        a_alt[i] = candies[i] * f;
        prefsum[i] = prefsum[i - 1] + a_alt[i];
        multsum[i] = multsum[i - 1] + a_alt[i] * i;
        f *= -1;
    }

    long long ans = 0;
    while(q--) {
        cin >> op >> l >> r;
        if (op == 'U') {
            candies[l] = r;
            f = 1;
            for (int i = 1; i <= n; i++) {
                a_alt[i] = candies[i] * f;
                prefsum[i] = prefsum[i - 1] + a_alt[i];
                multsum[i] = multsum[i - 1] + a_alt[i] * i;
                f *= -1;
            }
        } else {
            long long mult = multsum[r] - multsum[l - 1];
            long long sumsum = prefsum[r] - prefsum[l - 1];
            ans += (l % 2 == 0 ? -1 : 1) * (mult - (l - 1) * sumsum);
        }
    }

    cout << "Case #" << t << ": " << ans << '\n';

}

int main(void) {_
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
