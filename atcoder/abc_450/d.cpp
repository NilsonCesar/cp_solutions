#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] % k;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) ans = max(ans, a[i + 1] - a[i]);
    ans = max(ans, k - a[n - 1] + a[0]);
    cout << k - ans << '\n';
    return 0;
}
