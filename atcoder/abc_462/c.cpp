#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, x, y, ans = 0;
    cin >> n;
    vector<vector<int>> coords;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({x, y});
    }

    sort(coords.begin(), coords.end());
    ans++;
    int yMin = coords[0][1];

    for (int i = 1; i < n; i++) {
        x = coords[i][0], y = coords[i][1];

        if (y < yMin) {
            ans++;
            // cout << x << ' ' << y << '\n';
            yMin = y;
        }
    }

    cout << ans << '\n';

    return 0;
}
