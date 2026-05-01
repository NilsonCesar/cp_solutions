#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m;
    char c;
    cin >> n >> m;
    int x = -1, y = -1, ans = 0, px, py;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '@') {
                px = i;
                py = j;
            }
        }
        if (x == -1) {
            x = px;
            y = py;
        }

        ans += abs(x - px) + abs(y - py);
        x = px;
        y = py;
    }
    cout << ans << '\n';

    return 0;
}
