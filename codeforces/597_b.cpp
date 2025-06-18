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
    int n, a, b, ans = 0;
    cin >> n;
    vector<pair<int, int>> orders;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        orders.push_back({b, a});
    }
    sort(orders.begin(), orders.end());

    a = 0;
    for (int i = 0; i < n; i++) {
        if (orders[i].second > a) {
            ans++;
            a = orders[i].first;
        }
    }

    cout << ans << '\n';

    return 0;
}
