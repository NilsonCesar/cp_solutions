#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    bool now_all_zero = false;
    char ans = 'S';
    for (int i = 0; i < n; i++) {
        int pivot = -1;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] && !now_all_zero) {
                pivot = j;
                break;
            } else if (grid[i][j] && now_all_zero) {
                ans = 'N';
            }
        }

        if (pivot == -1) {
            now_all_zero = true;
        } else {
            for (int k = i + 1; k < n; k++) {
                if (grid[k][pivot]) {
                    ans = 'N';
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
