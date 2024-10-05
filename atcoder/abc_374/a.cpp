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
    int n = (int) s.length();
    if(s[n - 3] == 's' && s[n - 2] == 'a' && s[n - 1] == 'n') cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}
