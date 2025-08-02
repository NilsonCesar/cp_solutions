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
    double i = 0, j = 2e9;
    double ans = 1e10, mid;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(2));

    for (int k = 0; k < n; k++) 
        cin >> a[k][0] >> a[k][1];
    sort(a.begin(), a.end());

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for(int t = 0; t < 100; t++) {
        // cout << i << ' ' << j << ' ' << prev_mid << '\n';
        mid = i + ((j - i) * 1.0) / 2.0;
    
        double maxL = -2e9, minR = 2e9;
        bool done = true;

        for (int k = 0; k < n; k++) {
            maxL = max(maxL, a[k][0] - a[k][1] * mid);
            minR = min(minR, a[k][0] + a[k][1] * mid);
        }

        if (maxL <= minR) {
            ans = mid;
            j = mid;
        } else i = mid;
    }
    
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
