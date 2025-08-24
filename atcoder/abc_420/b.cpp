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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int x, y, maxPoint = 0;
    vector<int> ans(n, 0);

    for (int j = 0; j < m; j++) {
        x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (s[i][j] == '1') x++;
            else y++;
        }

        if (x == 0 || y == 0) {
            for (int k = 0; k < n; k++) ans[k]++;
            maxPoint++;
        } else if (x < y) {
            for (int k = 0; k < n; k++)
                if (s[k][j] == '1') {
                    ans[k]++;
                    maxPoint = max(maxPoint, ans[k]);
                }
        } else {
            for (int k = 0; k < n; k++)
                if (s[k][j] == '0') {
                    ans[k]++;
                    maxPoint = max(maxPoint, ans[k]);
                }
        }
    }

    for (int i = 0; i < n; i++)
        if (ans[i] == maxPoint)
            cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}
