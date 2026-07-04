#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t, ans;
    long long x, y, k;
    cin >> t;
    while(t--) {
        cin >> x >> y >> k;
        ans = 0;

        while(x != y) {
            if (x < y) swap(x, y);
            x /= k;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
