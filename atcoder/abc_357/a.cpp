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
    mainIO("");
    int n, m, ans = 0, h;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> h;
        m -= h;
        if(m >= 0)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
