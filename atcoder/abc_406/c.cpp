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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<char, long long>> v;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            if (v.empty() or v.back().first == '>') v.push_back({'<', 1});
            else v.back().second++;
        } else {
            if (v.empty() or v.back().first == '<') v.push_back({'>', 1});
            else v.back().second++;
        }
    }

    long long ans = 0;
    int sz = (int) v.size();

    for (int i = 1; i < sz - 1; i++) if (v[i].first == '>') ans += v[i - 1].second * v[i + 1].second;

    cout << ans << '\n';

    return 0;
}