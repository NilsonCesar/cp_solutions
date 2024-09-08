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
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == 0) cout << "Yes";
    else if(l == 0 && r == 1) cout << "No";
    else cout << "Invalid";
    cout << '\n';
    return 0;
}
