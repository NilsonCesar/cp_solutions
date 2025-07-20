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
    unsigned long long ans = 0;
    cin >> n >> m;
    vector<long long> x(n), dists(n - 1);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    for (int i = 0; i < n - 1; i++) dists[i] = x[i + 1] - x[i];
    sort(dists.begin(), dists.end());

    for (int i = 0; i < n - m; i++) ans += dists[i];

    cout << ans << '\n';

    return 0;
}
