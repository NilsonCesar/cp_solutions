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

    int y;
    cin >> y;

    if(y % 4 != 0) cout << 365;
    else if(y % 400 == 0) cout << 366;
    else if(y % 100 == 0) cout << 365;
    else cout << 366;
    cout << '\n';

    return 0;
}
