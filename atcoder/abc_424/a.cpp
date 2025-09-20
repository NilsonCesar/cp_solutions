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
    cout << (a == b || a == c || b == c ? "Yes" : "No") << '\n';

    return 0;
}
