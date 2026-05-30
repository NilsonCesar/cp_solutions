#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int l, t, x, y, r;
    cin >> l >> t;
    vector<vector<int>> places(l, vector<int>(2));
    for (int i = 0; i < l; i++) cin >> places[i][0] >> places[i][1];

    vector<vector<int>> grid(501, vector<int>(501, 0));

    for (int i = 0; i < t; i++) {
        cin >> x >> y >> r;

        for (int j = max(0, x - r); j <= min(500, x + r); j++) {
            for (int k = max(0, y - r); k <= min(500, y + r); k++) {
                grid[j][k]++;
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < l; i++)
        ans += grid[places[i][0]][places[i][1]];
    cout << ans << '\n';

    return 0;
}
