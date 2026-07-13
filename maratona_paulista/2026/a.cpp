#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, d, o;
    cin >> n >> q;

    vector<int> c(n), s(n), nxt(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    nxt[n - 1] = n;

    for (int i = n - 2; i >= 0; i--) {
        nxt[i] = (s[i] != s[i + 1] ? i + 1 : nxt[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        cin >> d >> o;
        int pos = lower_bound(c.begin(), c.end(), d, greater<int>()) - c.begin();
        if (pos < n && s[pos] == o)
            pos = nxt[pos];
        cout << (pos == n ? -1 : pos + 1) << '\n';
    }

    return 0;
}