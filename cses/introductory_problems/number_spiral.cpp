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
        long long x, y;
        cin >> x >> y;
        long long c = max(x, y);
        if (c % 2)
            cout << c * c - abs(1 - x) - abs(c - y);
        else
            cout << c * c - abs(c - x) - abs(1 - y);
        cout << '\n';
    }

    return 0;
}
