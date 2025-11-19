#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);

int main(void) {_
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1, actMax = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > actMax) {
            actMax = a[i];
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
