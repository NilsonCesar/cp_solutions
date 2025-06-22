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
    int t, ans, tmp;
    cin >> t;
    while(t--) {
        string s;
        ans = 0, tmp = 0;
        cin >> s;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == 'L') tmp++;
            else tmp = 0;
            ans = max(tmp, ans);
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}
