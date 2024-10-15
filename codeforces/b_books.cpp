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

    int n, t, ans = 0;
    cin >> n >> t;
    vector<int> sumpref(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> sumpref[i];
        sumpref[i] += sumpref[i - 1];
    }

    for(int i = 0; i <= n; i++) {
        auto j = upper_bound(sumpref.begin(), sumpref.end(), t + sumpref[i]);
        ans = max(ans, (int) (j - sumpref.begin()) - i - 1);
    }

    cout << ans << '\n';

    return 0;
}
