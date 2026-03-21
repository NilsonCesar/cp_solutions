#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    int c[n + 1][n + 1] = {0};
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            for (int cc = b + 1; cc <= n; cc++) {
                if (c[a][b] + c[b][cc] < c[a][cc]) {
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "No" << '\n';

    return 0;
}
