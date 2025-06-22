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
    int t, n, k, ans, c = 0;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if (k < n) cout << k;
        else if (k == n) cout << k + 1;
        else {
            c = 0;
            ans = k;
            while (k > n) {
                c += k % n;
                k /= n;
                ans += k;
            }
            if (ans % n == 0) ans++;
            cout << ans + (c / (n - 1));
        }
        cout << '\n';
    }

    return 0;
}
