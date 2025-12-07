#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sumpref = 0, even = 1, odd = 0;
    long long ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sumpref += a[i];
        if (sumpref % 2 != 0) {
            ans += even;
            odd++;
        } else {
            ans += odd;
            even++;
        }
    }

    cout << ans << '\n';


    return 0;
}