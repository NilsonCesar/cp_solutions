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
    int n, m, l, r;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int> sumpref(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        sumpref[l - 1] += 1;
        sumpref[r] -= 1;
    }

    for (int i = 1; i <= n; i++)
        sumpref[i] += sumpref[i - 1];

    for (int i = 0; i < n; i++)
        cout << (sumpref[i] % 2 ? t[i] : s[i]);
    cout << '\n';

    return 0;
}
