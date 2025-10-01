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
    int t, a, b, c;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if ((a == 0 && b == 3) || (a == 3 && b == 0) || (a * 2 < b ) || (b * 2 < a)) {
            cout << "NO" << '\n';
            continue;
        }
        a = a % 3;
        b = b % 3;
        c = max(a, b);
        a = min(a, b);
        b = c;

        if ((a == 0 && b == 0) || (a == 1 && b == 2)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}
