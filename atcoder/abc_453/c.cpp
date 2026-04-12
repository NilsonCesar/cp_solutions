#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, ans = 0;
vector<int> pos(20, 0), l(20, 0);

void solve(int i) {
    if (i == n) {
        int tmpAns = 0;
        double t = 0.5;
        for (int j = 0; j < n; j++) {
            double shift = (pos[j] * l[j]);
            if (t > 0 && t + shift < 0) tmpAns++;
            if (t < 0 && t + shift > 0) tmpAns++;
            t += shift;
        }
        ans = max(ans, tmpAns);
    } else {
        pos[i] = 1;
        solve(i + 1);
        pos[i] = -1;
        solve(i + 1);
    }
}

int main(void) {_
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    solve(0);

    cout << ans << '\n';

    return 0;
}
