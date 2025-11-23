#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, a;
    cin >> n;
    vector<int> bits(31);
    for (int i = 0; i < n; i++) {
        cin >> a;
        int mask = 1;
        while (a) {
            // cout << a << '\n';
            if (a & 1) {
                bits[mask]++;
            }
            a = a >> 1;
            mask++;
        }
    }

    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int i = 1; i < 31; i++) {
            if (bits[i]) {
                bits[i]--;
                ans += pow(2, i - 1);
            }
        }

        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}