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
    int n;
    string s;
    cin >> n >> s;
    if (n < 3) {
        cout << "No" << '\n';
        return 0;
    }

    if (s[n - 3] == 't' and s[n - 2] == 'e' and s[n - 1] == 'a') {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
