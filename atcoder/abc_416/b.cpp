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
    int n = (int) s.size();
    string t(n, '.');
    for (int i = 0; i < n; i++)
        if (s[i] == '#')
            t[i] = '#';
    
    bool has_hashtag = true;
    for (int i = 0; i < n; i++) {
        if (t[i] == '#') {
            has_hashtag = true;
        } else if (t[i] == '.' && has_hashtag) {
            t[i] = 'o';
            has_hashtag = false;
        }
    }

    cout << t << '\n';

    return 0;
}
