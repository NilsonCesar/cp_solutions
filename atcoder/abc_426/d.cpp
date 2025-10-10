#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int find_greatest_gap(string s, int d, int n) {
    int l = 0, r = 1, max_saved = 0;
    while(l < n && s[l] != d) {
            l++; r++;
    }
    while (r < n) {
        if (s[r] != d) {
            max_saved = max(max_saved, r - l);
            l = r;
            r++;
            while(l < n && s[l] != d) {
                l++; r++;
            }
        } else r++;
    }

    if (l < n && s[l] == d) {
        max_saved = max(max_saved, r - l);
    }

    return max_saved;
}

int main(void) {
    mainIO();
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int n0 = 0, n1 = 0;
        for (int i = 0; i < n; i++) {
            n0 += s[i] == '0';
            n1 += s[i] == '1';
        }

        int q0 = 2 * (n0 - find_greatest_gap(s, '0', n));
        int q1 = 2 * (n1 - find_greatest_gap(s, '1', n));
        
        cout << min(n1 + q0, n0 + q1) << '\n';
    }
    return 0;
}
