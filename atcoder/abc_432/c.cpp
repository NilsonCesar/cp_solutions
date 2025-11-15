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
    int n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    long long d = y - x;
    cin >> a[0];
    long long r = (a[0] * x) % d, ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if ((a[i] * x) % d != r) {
            ans = -1;
        }
    }

    if (ans == -1) {
        cout << ans << '\n';
        return 0;
    }

    long long w_min = a[0] * x, w_max = a[0] * y;

    for (int i = 1; i < n; i++) {
        w_min = max(w_min, a[i] * x);
        w_max = min(w_max, a[i] * y);
    }

    if (w_min > w_max) {
        cout << -1 << '\n';
        return 0;
    }

    long long w;

    if (w_max % d == r) w = w_max;
    else if (w_max - (w_max % d) + r < w_max) w = w_max - (w_max % d) + r;
    else w = w_max - (w_max % d) + r - d;

    if (w < w_min) {
        cout << -1 << '\n';
        return 0;
    }

    ans = 0;
    for (int i = 0; i < n; i++) 
        ans += (w - (a[i] * x)) / d;
    cout << ans << '\n';

    return 0;
}
