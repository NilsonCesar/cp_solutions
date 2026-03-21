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
    mainIO("sort");
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first;
        cows[i].second = i;
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cows[i].second - i);
    }
    cout << ans + 1 << '\n';
    return 0;
}
