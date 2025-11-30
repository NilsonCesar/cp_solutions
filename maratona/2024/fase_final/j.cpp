#include <bits/stdc++.h>
 
using namespace std;
 
#define m_pi 3.14159265358979323846
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, u;
    double x, h;
    double ans = 0;
    cin >> t >> n;
    vector<pair<double, double>> coords(n), x_axis;
    vector<bool> to_ignore(n + 7, false);
    map<int, double> p_to_x;
    cout << setprecision(15);
    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        coords[i].first = x;
        coords[i].second = x + (h * 1.0) / (sin(t * m_pi / 180.00) / cos (t * m_pi / 180.00));
    }
    sort(coords.begin(), coords.end());
 
    for (int i = 0; i < n; i++) {
        x_axis.push_back({coords[i].first, coords[i].second});
        // cout << coords[i].first << ' ' << coords[i].second << '\n';
    }
 
    sort(x_axis.begin(), x_axis.end());
    double l = x_axis[0].first, r = x_axis[0].second;
    int i = 1;
    while (i < n) {
        double ll = max(l, x_axis[i].first), rr = min(r, x_axis[i].second);
        i++;
        // cout << "here" << '\n';
        // cout << l << ' ' << r  << ' ' << ans << '\n';
        // cout << ll << ' ' << rr << '\n';
        if (rr - ll == x_axis[i].second - x_axis[i].first) continue;
        if (ll > rr) {
            ans += r - l;
            l = x_axis[i - 1].first;
            r = x_axis[i - 1].second;
        } else {
            ans += ll - l;
            l = x_axis[i - 1].first;
            r = x_axis[i - 1].second;
        }
    }

    cout << ans + r - l << '\n';

    return 0;
}