#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

long long calc_ballons(long long t, long long z, long long y, long long T) {
    return  T / (y + z * t) * z + min(z * t, T % (y + z * t)) / t;
}

int main(void) {
    mainIO();
    long long n, m, ans, l = 0, r = 1e9, mid, tmp_b;
    cin >> m >> n;
    vector<vector<long long>> a(n, vector<long long>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    while (l <= r) {
        mid = l + (r - l) / 2;
        tmp_b = 0;
        for (int i = 0; i < n; i++) 
            tmp_b += calc_ballons(a[i][0], a[i][1], a[i][2], mid);
        
        if (tmp_b >= m) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    long long remaining = m;
    for (int i = 0; i < n; i++) {
        long long b = calc_ballons(a[i][0], a[i][1], a[i][2], ans);
        if (remaining < b) cout << remaining;
        else cout << b;
        cout << ' ';
        remaining -= min(b, remaining);
    }
    cout << '\n';
    return 0;
}
