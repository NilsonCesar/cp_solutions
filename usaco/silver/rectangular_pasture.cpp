#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;

    vector<int> xs(n), ys(n);

    for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];

    vector<int> sx = xs;
    sort(sx.begin(), sx.end());
    for (int i = 0; i < n; i++)
        xs[i] = lower_bound(sx.begin(), sx.end(), xs[i]) - sx.begin() + 1;
        
    vector<int> sy = ys;
    sort(sy.begin(), sy.end());
    for (int i = 0; i < n; i++)
        ys[i] = lower_bound(sy.begin(), sy.end(), ys[i]) - sy.begin() + 1;

    vector<vector<int>> prefix(n + 7, vector<int>(n + 7, 0)), grid(n + 7, vector<int>(n + 7, 0));

    for (int i = 0; i < n; i++) grid[xs[i]][ys[i]] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i][j];
        }
    }

    long long ans = n + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (xs[i] >= xs[j]) continue;
            int y_min = min(ys[i], ys[j]);
            int y_max = max(ys[i], ys[j]);
            long long below = prefix[xs[j]][y_min - 1] - prefix[xs[i] - 1][y_min - 1];
            long long above = prefix[xs[j]][n] - prefix[xs[i] - 1][n] - prefix[xs[j]][y_max] + prefix[xs[i] - 1][y_max];
            ans += (below + 1) * (above + 1);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
