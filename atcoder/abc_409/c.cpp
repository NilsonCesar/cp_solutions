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
    long long n, l, ans = 0;
    cin >> n >> l;
    vector<int> a(n, 0);
    map<int, long long> f;
    f[0]++;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] = (a[i - 1] + a[i]) % l;
        f[a[i]]++;
    }

    sort(a.begin(), a.end());
    a.erase( unique( a.begin(), a.end() ), a.end() );

    if (l % 3 != 0) cout << 0 << '\n';
    else {
        for (int i = 0; i < (int) a.size(); i++) {
            ans += f[a[i]] * f[a[i] + l / 3] * f[a[i] + 2 * l / 3];
        }
        cout << ans << '\n';
    }

    return 0;
}
