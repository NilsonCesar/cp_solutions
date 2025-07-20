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
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '#') {
            cout << i + 1;
            if (!count) {
                cout << ',';
            } else {
                cout << '\n';
            }
            count = (count + 1) % 2;
        }
    }


    return 0;
}
