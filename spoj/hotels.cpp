#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    unsigned long long n, m;
    cin >> n >> m;
    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unsigned long long ans = 0;

    unsigned long long i = 0, j = 0, sum = a[0];
    while(j < n) {
        if (sum <= m) {
            j++;
            if (j < n) sum += a[j];
        } else {
            sum -= a[i];
            i++;
        }

        if (sum <= m) ans = max(ans, sum);
        // cout << sum << '\n';
        // cout << i << ' ' << j << '\n';
    }

    cout << ans << '\n';

    return 0;
}
