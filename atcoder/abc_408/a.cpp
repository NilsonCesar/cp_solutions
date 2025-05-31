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
    int n, s, cur = 0;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    for (int i = 0; i < n; i++) {
        if (cur + s < t[i]) {
            cout << "No" << '\n';
            return 0;
        } else {
            cur = t[i];
        }
    }

    cout << "Yes" << '\n';

    return 0;
}