#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> r(n, -1);
    vector<int> reach(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'x') {
            if (i + 1 < n && s[i + 1] == 'x') {
                r[i] = r[i + 1];
            } else {
                r[i] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            reach[i] = 2 * r[i] - i + 1;
        }
    }

    if (r[0] == n - 1) {
        cout << 0 << '\n';
        return;
    }

    int jumps = 0;
    int scan_start = r[0] + 1;
    int scan_end = reach[0];

    while(true) {
        jumps++;

        if (scan_end >= n - 1) {
            cout << jumps << '\n';
            return;
        }

        int next_scan_end = -1;

        for (int i = scan_start; i <= scan_end; i++) {
            if (s[i] == 'x') {
                if (r[i] == n - 1) {
                    cout << jumps << '\n';
                    return;
                }

                next_scan_end = max(next_scan_end, reach[i]);
            }
        }

        if (next_scan_end <= scan_end) {
            cout << -1 << '\n';
            return;
        }

        scan_start = scan_end + 1;
        scan_end = next_scan_end;

    }

    cout << jumps << '\n';
    return;
}

int main(void) {_
    int n; cin >> n;

    while(n--) {
        solve();
    }

    return 0;
}
