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
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; i++) cin >> d[i];
        int ans = 0, min_d = d[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (min_d > d[i]) min_d = d[i];
            else if (min_d < d[i]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
