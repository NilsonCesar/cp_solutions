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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int k = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(j == m) j--;
        if(k == m) k--;
        if(b[j] > a[i]) j = max(j - 1, 0);
        ans = max(ans, min(abs(b[j] - a[i]), abs(b[k] - a[i])));
        // cout << j << ' ' << k << '\n';
        // cout << max(ans, min(abs(b[j] - a[i]), abs(b[k] - a[i]))) << '\n'; 
    }
    
    cout << ans << '\n';

    return 0;
}
