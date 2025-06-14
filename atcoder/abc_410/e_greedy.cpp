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
    int n, h, m, a, b, ans = 0;
    cin >> n >> h >> m;
    vector<bool> done(n, false);
    vector<vector<int>> w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        w.push_back({a, i, 0});
        w.push_back({b, i, 1});
    }

    for (int i = 0; i < 2 * n; i++) {
        a = w[i][0];
        b = w[i][1];
        if (!done[b]) {
            if (!w[i][2] && h >= a) {
                ans++;
                h -= a;
                done[b] = true;
            } else if (m >= a) {
                ans++;
                m -= a;
                done[b] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
