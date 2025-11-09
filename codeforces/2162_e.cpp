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

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), ans(3);
        map<int, bool> included;
        int q = 0; 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!included[a[i]]) {
                included[a[i]] = true;
                q++;
            }
        }

        if (q == n) {
            ans[0] = a[0];
            ans[1] = a[1];
            ans[2] = a[2];
        } else {
            for (int i = 1; i <= n; i++)
                if (!included[i]) {
                    ans[0] = i;
                    break;
                }
            ans[2] = a[n - 1];
            for (int i = 1; i <= n; i++) 
                if (i != ans[0] && i != ans[2]) {
                    ans[1] = i;
                    break;
                }
        }

        for (int i = 0; i < k; i++) 
            cout << ans[i % 3] << ' ';
        cout << '\n';
    }

    return 0;
}
