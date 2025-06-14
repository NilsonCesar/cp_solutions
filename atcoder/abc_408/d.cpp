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
    int t;
    cin >> t;
    while(t--) {
        int n, totalOnes = 0;
        string s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') a[i] = -1;
            else {
                a[i] = 1;
                totalOnes++;
            }
        }
        vector<int> seq(n);
        seq[0] = max(a[0], 0);
        int m = seq[0];
        for (int i = 1; i < n; i++) {
            seq[i] = max(seq[i - 1] + a[i], a[i]);
            m = max(m, seq[i]);
        }
        cout << totalOnes - m << '\n';
    }

    return 0;
}