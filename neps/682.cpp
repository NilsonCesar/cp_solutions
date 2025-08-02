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
    long long n, k, minY = 1e9, maxY = -1e9;
    long long sum = 0;
    cin >> n >> k;
    vector<vector<long long>> a(n, vector<long long>(4));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        sum += (a[i][2] - a[i][0]) * (a[i][3] - a[i][1]);
        maxY = max(maxY, a[i][3]);
        minY = min(minY, a[i][1]);
    }

    if (sum < k) {
        cout << "PERDAO MEU REI" << '\n';
        return 0;
    }
    else if (sum == k) {
        cout << maxY << '\n';
        return 0;
    }
    long long mid, ans = -1;

    while (minY <= maxY) {
        mid = (minY + maxY) / 2;
        sum = 0;

        for (int i = 0; i < n; i++) 
            sum += (a[i][2] - a[i][0]) * (min(a[i][3], mid) - min(a[i][1], mid));
        
        if (sum >= k) {
            maxY = mid - 1;
            ans = mid;
        } else {
            minY = mid + 1;
        }
    }
    
    if (ans == -1) cout << "PERDAO MEU REI" << '\n';
    else cout << ans << '\n';

    return 0;
}
