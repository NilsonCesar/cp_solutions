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
    unsigned long long ans = 0;
    cin >> n;
    vector<unsigned long long> sumpref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sumpref[i];
        sumpref[i] += sumpref[i - 1];
    }

    for (int i = 1; i <= n - 1; i++)
        ans += (sumpref[i] - sumpref[i - 1]) * (sumpref[n] - sumpref[i]);

    cout << ans << '\n';

    return 0;
}