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
        int n, f = 0, c, l = 0;
        cin >> n;
        vector<int> a;
        cin >> c;
        a.push_back(c);
        f = a[0] > 0;
        long long ans = 0;

        for (int i = 1; i < n; i++) {
            cin >> c;
            if (f && c > 0 || !f && c < 0) {
                a[l] = max(a[l], c);
            } else if (f) {
                a.push_back(c);
                f = 0;
                ans += a[l];
                l++;
            } else if (c > 0) {
                a.push_back(c);
                f = 1;
                ans += a[l];
                l++;
            }
        }
        ans += a[l];

        cout << ans << '\n';
    }

    return 0;
}
