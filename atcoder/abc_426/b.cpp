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
    char ans;
    map<char, int> count;

    for (char c : s) {
        count[c]++;
    }

    for (char c : s) {
        if (count[c] == 1) ans = c;
    }

    cout << ans << '\n';

    return 0;
}
