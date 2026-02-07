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
    int d = a[0];
    int valid = 1;
    int max_d = -1, min_d = INF;
    for (int i = 0; i < n; i++) {
        max_d = max(max_d, a[i]);
        min_d = min(min_d, a[i]);
        if (d != a[i]) {
            valid = 0;
        }
    }

    if (valid) {
        cout << d;
        if (n % 2 == 0) {
            cout << ' ' << 2 * d;
        }
        cout << '\n';
        return 0;
    }

    vector<int> ans;
    d = min_d + max_d;
    valid = 1;

    sort(a.begin(), a.end());
    int i = 0, j = n - 1;

    while(i <= j) {
        if (a[j] == d) j--;
        else if (a[i] + a[j] == d) {
            i++;
            j--;
        } else {
            valid = 0;
            break;
        }
    }

    if (valid) ans.push_back(d);

    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
    }

    if (sum % max_d == 0) ans.push_back(max_d);

    if ((int) ans.size() == 1) {
        cout << ans[0];
    } else {
        cout << ans[1] << ' ' << ans[0];
    }
    cout << '\n';
    
    return 0;
}
