#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, ans = 0, a;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (h >= a) ans++;
    }
    cout << ans << '\n';
    return 0;
}