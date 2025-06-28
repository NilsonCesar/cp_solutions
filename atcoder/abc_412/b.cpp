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
    map<char, bool> T;
    bool ans = true;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < (int) t.size(); i++) T[t[i]] = true;

    for (int i = 1; i < (int) s.size(); i++)
        if (isupper(s[i]) && !T[s[i - 1]])
            ans = false;

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
