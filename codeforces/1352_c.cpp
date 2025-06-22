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
    int t, n, k, ans;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if (k < n) cout << k;
        else if (k == n) cout << k + 1;
        else {
            ans = k / (n - 1);
            // cout << ans << ' ' << k << '\n';
            if ((ans + k) % (n) == 0) cout << k + ans - 1;
            else cout << k + ans;
        }
        cout << '\n';
    }

    return 0;
}
