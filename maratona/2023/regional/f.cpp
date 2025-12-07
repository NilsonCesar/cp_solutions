#include <bits/stdc++.h>

using namespace std;

int main() {
    long long d, c, r;
    cin >> d >> c >> r;
    vector<int> C(c), R(r);

    for (int i = 0; i < c; i++) cin >> C[i];
    for (int i = 0; i < r; i++) cin >> R[i];

    int ans = 0, i = 0, j = 0;
    bool valid = true;

    while (valid) {
        if (i == c && j == r) break; 

        if (d >= C[i]) {
            d -= C[i];
            ans++;
            i++;
        } else if (j == r) break;
        else {
            while (j != r && d < C[i]) {
                d += R[j];
                j++;
                ans++;
            }
        }

        if (i == c) {
            ans += r - j;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}