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
    int q, n;
    cin >> q;

    while(q--) {
        cin >> n;
        if (n < 4) cout << 4 - n;
        else if (n % 2 == 0) cout << 0;
        else cout << 1;
        cout << '\n';
    }

    return 0;
}
