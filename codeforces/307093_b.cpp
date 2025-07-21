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
    int n, ans = 1e6, l = 0, r = 0;
    long long s, sum = 0;
    cin >> n >> s;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i]; 

    while (r <= n) {
        if (sum >= s) {
            ans = min(ans, r - l);
            sum -= a[l++];
        }
        else if (r < n) sum += a[r++];
        else break;
    }

    if (ans != 1e6) cout << ans;
    else cout << -1;
    cout << '\n';

    return 0;
}
