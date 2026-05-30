#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {
    int n, m;

    while(cin >> n >> m) {
        vector<vector<int>> grid(n, vector<int>(m));
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isBokuNoPico = true;
                for (int k = i - 1; k < i + 2; k++) {
                    if (k < 0 || k >= n) continue;
                    for (int l = j - 1; l < j + 2; l++) {
                        if (l < 0 || l >= m) continue;
                        if (k == i && l == j) continue;
                        if (grid[k][l] >= grid[i][j]) {
                            isBokuNoPico = false;
                        }
                    }
                }

                if (isBokuNoPico) {
                    ans.push_back({i + 1, j + 1});
                }
            }
        }

        for (pair<int, int> p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }

        if ((int) ans.size() == 0) {
            cout << -1 << '\n';
        }

        cout << '\n';
    }


    return 0;
}
