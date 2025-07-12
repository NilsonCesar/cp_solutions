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
    int n, l, r, x, y, ans = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x <= l and r <= y) ans++;
    }

    cout << ans << '\n';
    return 0;
}
