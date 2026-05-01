#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int c, n, s, num;
    int already;
    cin >> c;
    while(c--) {
        cin >> n >> s;
        int ans = 0, dist = INF; 
        already = false;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (already) continue;
            if (num == s) {
                cout << i + 1 << '\n';
                already = true;
            } else if (abs(s - num) < dist) {
                ans = i + 1;
                dist = abs(s - num);
            }
        }

        if (!already) cout << ans << '\n';
    }

    return 0;
}
