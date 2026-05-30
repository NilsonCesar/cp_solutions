#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int l, c, m, n;
    cin >> l >> c >> m >> n;
    
    vector<vector<long long>> grid(l, vector<long long>(c));

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    
    long long ans = -INF;

    for (int sx = 0; sx < l; sx+=m) {
        for (int sy = 0; sy < c; sy+=n) {
            long long tmp_ans = 0;
            for (int i = 0; i < m; i++) {
                if (i + sx >= l) {
                    tmp_ans = -INF;
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (j + sy >= c) {
                        tmp_ans = -INF;
                        break;
                    }
                    tmp_ans += grid[i + sx][j + sy];
                }
            }
            ans = max(ans, tmp_ans);
        }
    }

    cout << min(1000000ll, ans) << '\n';

    return 0;
}
