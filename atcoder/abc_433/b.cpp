#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, ans;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ans = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i]) {
                ans = j + 1;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
