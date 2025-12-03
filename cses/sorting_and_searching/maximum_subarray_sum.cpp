#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    int a;
    long long ans = -INF, current_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a;
        current_sum += a;
        ans = max(ans, current_sum);
        if (current_sum < 0) current_sum = 0;
    }

    cout << ans << '\n';

    return 0;
}
