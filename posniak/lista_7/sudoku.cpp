#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;

    for (int t = 1; t <= n; t++) {
        vector<vector<int>> sudoku(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> sudoku[i][j];
            }
        }

        string ans = "SIM";

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] <= 0 || sudoku[i][j] > 9) ans = "NAO";
            }
        }

        for (int sx = 0; sx < 9; sx += 3) {
            for (int sy = 0; sy < 9; sy += 3) {
                vector<bool> hit_num(10, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int num = sudoku[i + sx][j + sy];
                        if (hit_num[num]) {
                            ans = "NAO";
                        } else {
                            hit_num[num] = true;
                        }
                    }
                }

                for (int i = 1; i <= 9; i++) {
                    if (!hit_num[i]) ans = "NAO";
                }
            }
        }


        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                for (int j = 0; j < 9; j++) {
                    if (j == y) continue;
                    if (sudoku[x][y] == sudoku[x][j]) ans = "NAO";
                }

                for (int i = 0; i < 9; i++) {
                    if (i == x) continue;
                    if (sudoku[x][y] == sudoku[i][y]) ans = "NAO";
                }
            }
        }

        cout << "Instancia " << t << '\n' << ans << '\n' << '\n';
    }

    return 0;
}
