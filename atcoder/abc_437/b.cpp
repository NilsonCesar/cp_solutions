#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> b(n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;

    for (int i = 0; i < h; i++) {
        int cnt = 0;
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][j] == b[k]) {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
