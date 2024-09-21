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
    for(int i = 0; i < (int) s.size(); i++)
        if(s[i] != '.')
            cout << s[i];
    cout << '\n';

    return 0;
}
