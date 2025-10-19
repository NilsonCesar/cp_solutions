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
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int d = x / (a + b), r = x % (a + b);
    int ans = d * s * a + min(r, a) * s;
    cout << ans << '\n';
    return 0;
}
