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
        if (a % b)
            cout << b - (a % b) << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
