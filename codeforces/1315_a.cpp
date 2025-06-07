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
    int t, a, b, x, y;
    cin >> t;
    while(t--) {
        cin >> a >> b >> x >> y;
        cout << max(
            max(y * a, (b - y - 1) * a),
            max(x * b, (a - x - 1) * b)
        ) << '\n';
    }

    return 0;
}
