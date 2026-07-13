#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, c, k, d;
    cin >> n >> c >> k;
    long long ans = 0;
    long long ci = 0, cf = 0;
    cin >> d;

    ci = cf = d;

    for (int i = 1; i < n; i++) {
        cin >> d;

        long long agg = ans + (d - ci + 1) * c + k;
        long long sep = ans + (cf - ci + 1) * c + k + c + k;

        if (agg <= sep) {
            cf = d;
        } else {
            ans += (cf - ci + 1) * c + k;
            ci = cf = d;
        }   
    }

   
    ans += (cf - ci + 1) * c + k;
    

    cout << ans << '\n';

    return 0;
}