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
    int n, q, x;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    
    cin >> q;
    while (q--) {
        cin >> x;
        int ans = x;

        for (int i = 0; i < n; i++) {
            if (a[i][0] >= ans) ans += a[i][1];
            else ans = max(ans - a[i][2], 0);
        }

        cout << ans << '\n';
    }
    

    return 0;
}
