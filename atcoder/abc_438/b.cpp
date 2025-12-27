#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int calc_dist(char a, char b) {
    int d1 = a - '0';
    int d2 = b - '0';
    if (d1 >= d2) return d1 - d2;
    return 10 + d1 - d2;
}

int main(void) {_
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    int ans = INF;

    for (int i = 0; i <= n - m; i++) {
        int cnt = 0;
        for (int j = i; j - i < m; j++) {
            cnt += calc_dist(s[j], t[j - i]);
        }
        ans = min(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
