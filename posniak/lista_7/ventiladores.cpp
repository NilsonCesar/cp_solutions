#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int l, c, p;

    while((cin >> l >> c >> p) && (l != 0 || c != 0 || p != 0)) {
        p--;
        vector<vector<int>> grid(l, vector<int>(c));
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        int ok = true;
        for (int i = 0; i < l; i++) {
            if (grid[i][p]) {
                ok = false;
                cout << "BOOM " << i + 1 << ' ' << p + 1;
                break;
            }
            
            int b1 = 0, b2 = 0, i1 = -1, i2 = c;
            for (int k = 0; k < c; k++) {
                if (k < p && grid[i][k]) {
                    b1 = grid[i][k];
                    i1 = k;
                }

                if (k > p && grid[i][k]) {
                    b2 = grid[i][k];
                    i2 = k;
                    break;
                }
            }

            int diff = b2 - b1;

            // cout << diff << ' ' << p << '\n';
            if (diff > 0) {
                if (p - diff <= i1) {
                    ok = false;
                    cout << "BOOM " << i + 1 << ' ' << i1 + 1;
                    break;
                }
                p -= diff;
            } else {
                if (p - diff >= i2) {
                    ok = false;
                    cout << "BOOM " << i + 1 << ' ' << i2 + 1;
                    break;
                }
                p -= diff;
            }
        }

        if (ok) cout << "OUT " << p + 1;
        cout << '\n';
    }

    return 0;
}
