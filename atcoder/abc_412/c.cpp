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
        int n, ans = 1;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        int a = s[0], b = s[n - 1], c = s[0];
        sort(s.begin(), s.end());

        if (a * 2 >= b) {
            cout << 2 << '\n';
            continue;
        }

        while (c < b) {
            c = s[upper_bound(s.begin(), s.end(), 2 * c) - s.begin() - 1];
            // cout << a << ' ' << c << '\n';
            if (c == a) {
                ans = -1;
                break;
            }
            a = c;
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
