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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), pref(n + 1, -1), suff(n + 2, -1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 1;
        for (int i = 1; i <= n; i++) pref[i] = max(pref[i - 1], a[i]);
        for (int i = n; i >= 1; i--) suff[i] = max(suff[i + 1], a[i]);
        for (int i = 1; i < n; i++) {
            if (a[i] < pref[i - 1] && a[i] < suff[i + 1]) ans = i - 1;
        }

        cout << ans << '\n';
    }


    return 0;
}
