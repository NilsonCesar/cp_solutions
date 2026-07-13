#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    int st = 300, et = 300;

    for (int i = 0; i < n; i++) {
        cin >> t;

        if ((et <= 420 && et + t > 420) || (et <= 1020 && et + t > 1020)) {
            et += t + 180;
        } else {
            et += t;
        }
    }

    cout << (et - st) << '\n';

    return 0;
}