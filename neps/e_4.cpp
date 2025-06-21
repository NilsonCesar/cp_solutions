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
    int n, m, prev_dist, c;
    long long ans = 0;
    cin >> n >> m >> ans;
    prev_dist = min(ans, m - ans);
    ans = prev_dist;

    for (int i = 1; i < n; i++) {
        cin >> c;
        c = min(c, m - c);
        if (c >= prev_dist) {
            ans += c;
            prev_dist = c;
        } else if (m - c >= prev_dist) {
            ans += m - c;
            prev_dist = m - c;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
