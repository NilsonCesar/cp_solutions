#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

set<char> mirrored_chars = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

string s;

int calc_len(int i, int j) {
    while (i >= 0 && j < (int) s.size() && s[i] == s[j] && mirrored_chars.find(s[i]) != mirrored_chars.end()) {
        i--;
        j++;
    }
    return j - i - 1;
}

int main(void) {
    mainIO();
    int q;
    cin >> q;

    while(q--) {
        cin >> s;
        int ans = 0, n = (int) s.size();

        for (int i = 0; i < n; i++) {
            int len = calc_len(i, i);
            ans = max(len, ans);
            len = calc_len(i, i + 1);
            ans = max(len, ans);
        }
        
        cout << ans << '\n';
    }

    return 0;
}
