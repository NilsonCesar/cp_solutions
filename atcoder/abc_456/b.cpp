#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int num;
    map<int, map<int, int>> dices;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> num;
            dices[i][num]++;
        }
    }

    double ans = 0;

    for (int i = 4; i <= 6; i++) {
        for (int j = 4; j <= 6; j++) {
            if (i == j) continue;
            for (int k = 4; k <= 6; k++) {
                if (j == k || i == k) continue;
                ans += (dices[1][i] * dices[2][j] * dices[3][k]) * 1.0 / 216.0; 
            }
        }
    }

    cout << fixed << setprecision(10);

    cout << ans << '\n';

    return 0;
}
