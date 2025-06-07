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
    int t, a, b;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        if (a == b) cout << 0;
        else if (a < b && (b - a) % 2 == 1) cout << 1;
        else if (a < b) cout << 2;
        else if (a > b && (a - b) % 2 == 0) cout << 1;
        else cout << 2;
        cout << '\n';
    }

    return 0;
}
