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
    int h, w, n, x, y, q;
    cin >> h >> w >> n;
    vector<vector<int>> vh(h + 1, vector<int>()), vw(w + 1, vector<int>());
    vector<bool> used(n + 1, false), used_h(h + 1, false), used_w(w + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vh[x].push_back(i);
        vw[y].push_back(i);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> y >> x;
        if (y == 1) {
            if (used_h[x]) cout << 0 << '\n';
            else {
                int ans = 0;
                for (int e: vh[x]) {
                    if (used[e]) continue;
                    ans++;
                    used[e] = true;
                }
                cout << ans << '\n';
                used_h[x] = true;
            }
        } else {
            if (used_w[x]) cout << 0 << '\n';
            else {
                int ans = 0;
                for (int e: vw[x]) {
                    if (used[e]) continue;
                    ans++;
                    used[e] = true;
                }
                cout << ans << '\n';
                used_w[x] = true;
            }
        }
    }

    return 0;
}