#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int m, d;
    cin >> m >> d;
    string g;
    cin >> g;
    vector<bool> p(m, false);

    for (int i = 0; i < m; i++) {
        if (g[i] != 'G') continue;
        int back = i - d, front = i + d;
        for (int j = max(0, back); j < min(m, front + 1); j++) {
            p[j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) ans += !p[i];
    cout << ans << '\n';

    return 0;
}
