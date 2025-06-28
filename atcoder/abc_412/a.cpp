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
    int n, a, b, ans = 0;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        ans += b > a;
    }
    cout << ans << '\n';

    return 0;
}
