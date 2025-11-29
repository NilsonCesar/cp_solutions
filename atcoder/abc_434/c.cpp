#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void solve() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> goals(n + 1);
    vector<int> t(n + 1);
    t[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> goals[i].first >> goals[i].second;
    int l = h, r = h;

    for (int i = 1; i <= n; i++) {
        l -= t[i] - t[i - 1];
        r += t[i] - t[i - 1];
        l = max(l, goals[i].first);
        r = min(r, goals[i].second);
        if (l > r) {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main(void) {_
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
