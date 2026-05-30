#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, s;

    while((cin >> n >> m >> s) && (n != 0 || m != 0 || s != 0)) {
        vector<vector<char>> grid(n, vector<char>(m));
        int ri, rj;
        char orientation;
        set<char> orientations = {'N', 'S', 'O', 'L'};
        set<pair<int, int>> figs;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (orientations.count(grid[i][j])) {
                    orientation = grid[i][j];
                    ri = i;
                    rj = j;
                }
            }
        }

        string instructions;
        cin >> instructions;

        for (char instruction : instructions) {
            int ti = ri, tj = rj;
            if (instruction == 'F') {
                if (orientation == 'N') {
                    ti = max(0, ri - 1);
                } else if (orientation == 'S') {
                    ti = min(n - 1, ri + 1);
                } else if (orientation == 'L') {
                    tj = min(m - 1, rj + 1);
                } else {
                    tj = max(0, rj - 1);
                }

                if (grid[ti][tj] == '#') continue;
                if (grid[ti][tj] == '*') {
                    figs.insert({ti, tj});
                }
                ri = ti;
                rj = tj;
            } else if (instruction == 'D') {
                if (orientation == 'N') {
                    orientation = 'L';
                } else if (orientation == 'L') {
                    orientation = 'S';
                } else if (orientation == 'S') {
                    orientation = 'O';
                } else if (orientation == 'O') {
                    orientation = 'N';
                }
            } else {
                if (orientation == 'N') {
                    orientation = 'O';
                } else if (orientation == 'O') {
                    orientation = 'S';
                } else if (orientation == 'S') {
                    orientation = 'L';
                } else if (orientation == 'L') {
                    orientation = 'N';
                }
            }
        }

        cout << (int) figs.size() << '\n';

    }


    return 0;
}
