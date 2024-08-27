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
    int a, b, c;
    cin >> a >> b >> c;

    if(b < c) {
        if(a > b && a < c) cout << "No";
        else cout << "Yes";
    } else {
        if(a < c || a > b) cout << "No";
        else cout << "Yes";
    }
    cout << '\n';

    return 0;
}
