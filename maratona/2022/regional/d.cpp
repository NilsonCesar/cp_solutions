#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, ans = 0;
    long long x, y;
    cin >> n >> x >> y;

    long long min_x = 0;
    long long max_x = (1LL << n);
    long long min_y = 0;
    long long max_y = (1LL << n);

    while(true) {
        long long mid_x = (min_x + max_x) / 2;
        long long mid_y = (min_y + max_y) / 2;

        if (x == mid_x && y == mid_y) {
            break;
        }

        if (x < mid_x) {
            max_x = mid_x;
        } else {
            min_x = mid_x;
        }

        if (y < mid_y) {
            max_y = mid_y;
        } else {
            min_y = mid_y;
        }

        ans++;
    }

    cout << ans << '\n';

    return 0;
}