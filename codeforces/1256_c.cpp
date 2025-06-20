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
    int n, m, d, i = 0, dist = 0, p = 0;
    cin >> n >> m >> d;
    vector<int> w(n), ans;
    for (int i = 0; i < m; i++) {
        cin >> w[i];
        for (int j = p; j < p + d - 1; j++) ans.push_back(0);
        for (int j = p + d - 1; j < p + d - 1 + w[i]; j++) ans.push_back(i + 1);
        p += d + (w[i] - 1);
    }
    for (int i = p; i < n; i++) ans.push_back(0);
    p += d;

    if (p <= n) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    
    if ((int) ans.size() == n) {
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    } else {
        int diff = -n + (int) ans.size();
        for (int i = 0; i < (int) ans.size(); i++) {
            if (ans[i] == 0 && diff) {
                diff--;
                continue;
            }
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
