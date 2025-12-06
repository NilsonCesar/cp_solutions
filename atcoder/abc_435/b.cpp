#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int sum = 0;
            for (int i = l; i <= r; i++) sum += a[i];
            bool valid = true;
            for (int i = l; i <= r; i++) {
                if (sum % a[i] == 0) {
                    valid = false;
                    break;
                }
            }
            ans += valid;
        }
    }

    cout << ans << '\n';

    return 0;
}
