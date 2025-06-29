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
        int n, ans;
        cin >> n;
        vector<int> a(n);
        ans = n - 1;

        for (int i = 0; i < n; i++) cin >> a[i];

        if (n <= 2) {
            cout << 0 << '\n';
            continue;
        }
        
        while (ans > 0 && a[ans - 1] >= a[ans]) ans--;
        while (ans > 0 && a[ans - 1] <= a[ans]) ans--;

        cout << ans << '\n';
    }


    return 0;
}
