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
        unsigned long long x, y, a, b;
        cin >> x >> y >> a >> b;
        unsigned long long ans = 0, c = min(x, y);
        x -= c; y -= c;
        if (b * c < 2ull * a * c) 
            ans += b * c;
        else 
            ans += 2 * a * c;
        ans += a * (x + y);
        cout << ans << '\n';
    }

    return 0;
}