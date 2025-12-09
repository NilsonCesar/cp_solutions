#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a, ans = 0;
    cin >> n;
    map<int, int> m;
    int end = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (!m[a] || m[a] <= end) m[a] = i;
        else {
            ans = max(i - end - 1, ans);
            end = m[a];
            m[a] = i;
            // cout << "ans " << ans << " " << a << " " << m[a] << '\n';
        }
    }
    ans = max(ans, n - end);

    cout << ans << '\n';

    return 0;
}
