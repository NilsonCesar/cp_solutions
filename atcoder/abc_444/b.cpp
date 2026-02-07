#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int d = i;
        while (d > 0) {
            sum += d % 10;
            d /= 10;
        }
        ans += sum == k;
    }

    cout << ans << '\n';

    return 0;
}
