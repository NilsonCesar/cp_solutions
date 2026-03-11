#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, q;
    int x1, y1, x2, y2;
    char c;
    cin >> n >> q;

    vector<vector<int>> grid(n + 7, vector<int>(n + 7, 0)), diff(n + 7, vector<int>(n + 7, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            diff[i][j] = grid[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << diff[x2][y2] - diff[x1 - 1][y2] - diff[x2][y1 - 1] + diff[x1 - 1][y1 - 1] << '\n';
    }


    return 0;
}
