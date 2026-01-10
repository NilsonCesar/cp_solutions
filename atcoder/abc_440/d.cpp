#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, q, x, y;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(q--) {
        cin >> x >> y;
        int mx = x - 1 - (lower_bound(a.begin(), a.end(), x) - a.begin());  
        int t = y + mx;
        int l = x, r = 2 * 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int m = mid - (upper_bound(a.begin(), a.end(), mid) - a.begin());
            if (m >= t) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } 
        cout << ans << '\n';
    }

    return 0;
}
