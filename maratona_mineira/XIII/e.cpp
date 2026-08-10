#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int sx[5] = {0, 1, -1, 0, 0};
int sy[5] = {0, 0, 0, 1, -1};

int main(void) {_
    int n, m, t, g = 0, a = 0;
    cin >> n >> m >> t;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2, 0)), occ(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> moves_g(t), moves_a(t);

    for (int i = 0; i < t; i++) cin >> moves_g[i].first >> moves_g[i].second;
    for (int i = 0; i < t; i++) cin >> moves_a[i].first >> moves_a[i].second;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 5; j++) {
            occ[moves_g[i].first + sx[j]][moves_g[i].second + sy[j]]++;
            occ[moves_a[i].first + sx[j]][moves_a[i].second + sy[j]]++;
        }

        for (int j = 0; j < 5; j++) {
            if (occ[moves_g[i].first + sx[j]][moves_g[i].second + sy[j]] == 1) {
                g += grid[moves_g[i].first + sx[j]][moves_g[i].second + sy[j]];
                grid[moves_g[i].first + sx[j]][moves_g[i].second + sy[j]] = 0;
            }

            if (occ[moves_a[i].first + sx[j]][moves_a[i].second + sy[j]] == 1) {
                a += grid[moves_a[i].first + sx[j]][moves_a[i].second + sy[j]];
                grid[moves_a[i].first + sx[j]][moves_a[i].second + sy[j]] = 0;
            }
        }

        for (int j = 0; j < 5; j++) {
            occ[moves_g[i].first + sx[j]][moves_g[i].second + sy[j]]--;
            occ[moves_a[i].first + sx[j]][moves_a[i].second + sy[j]]--;
        }
    }


    cout << g << ' ' << a << '\n';

    return 0;
}