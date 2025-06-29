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
    int n, k;
    double l = 0, r = 1000, diff, ans = -1, its = 100;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    

    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    while (its--) {
        diff = 0;
        double mid = (l + r) * 1.0 / 2;
        ans = mid;
        for (int i = 0; i < n; i++) {
            double x = 1.0 * a[i];
            if (x > mid) {
                diff += (x - mid) * ((100 - k) * 1.0 / 100);
                // cout << diff << '\n';
            } else if (x < mid) diff -= mid - (x * 1.0);
        }
        // cout << mid << ' ' << diff << '\n';
        // cout << l << ' ' << mid << ' ' << r << ' ' << diff << '\n';
        if (diff <= 0) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}
