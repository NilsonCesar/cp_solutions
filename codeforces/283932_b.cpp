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
    int n, k, tmp_k;
    double sum = 0;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] * 1.0;
    }

    int time = 100;
    double l = 0, r = sum, mid, ans = 0;
    // cout << l << ' ' << r << ' ' << mid << '\n';

    while (time--) {
        mid = (l + r) / 2.0;
        if (mid < 1e-9) { 
            l = mid;
            continue;
        }
        // cout << "In binary search: " <<  mid << '\n';
        tmp_k = 0;
        for (int i = 0; i < n; i++) 
            tmp_k += (int) (a[i] / mid);
        
        // cout << "tmpK: " << tmp_k << '\n';
        // cout << "last mid: " <<  ans << '\n';
        if (tmp_k >= k) {
            ans = mid;
            l = mid;
        } else if (tmp_k < k) {
            r = mid;
        }

    }

    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}
