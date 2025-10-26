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
    string s, ans = "";
    cin >> s;

    vector<int> f(26, 0);
    for (int i = 0; i < (int) s.size(); i++) {
        f[s[i] - 'A']++;
    }

    for (int i = 0; i < (int) s.size(); i++) {
        bool valid = false;

        for (char c = 'A'; c <= 'Z'; c++) {
            int freq = f[c - 'A'];

            if (freq == 0) continue;

            if (!ans.empty() && ans.back() == c) continue;

            int max_freq = 0;
            f[c - 'A']--;
            
            for (int fr : f)
                if (max_freq < fr)
                    max_freq = fr;
            
            if (max_freq * 2 > (int) s.size() -i) {
                f[c - 'A']++;
                continue;
            }

            ans += c;
            valid = true;
            break;
        }

        if (!valid) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
