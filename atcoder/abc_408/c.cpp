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
    int n, m, ans = 1e6;
    cin >> n >> m;
    vector<int> sumpref(n + 2, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        sumpref[l]++;
        sumpref[r + 1]--;
    }

    for (int i = 1; i <= n; i++) sumpref[i] += sumpref[i - 1];
    for (int i = 1; i <= n; i++) ans = min(ans, sumpref[i]);
    
    cout << ans << '\n'; 

    return 0;
}