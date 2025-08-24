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
    int x, y;
    cin >> x >> y;
    if ((x + y) % 12 == 0) cout << 12;
    else cout << (x + y) % 12;
    cout << '\n';

    return 0;
}
