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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> ts;

    for (int i = 0; i < n; i++) {
        if (s[i] == 't') {
            ts.push_back(i);
        }
    }

    double ans = 0;

    for (int i = 0; i < (int) ts.size(); i++) {
        for (int j = i + 1; j < (int) ts.size(); j++) {
            if (ts[j] - ts[i] + 1 < 3) continue;
            ans = max(ans, (j - i - 1) * 1.0 / (ts[j] - ts[i] - 1) * 1.0);
        }
    }

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}
