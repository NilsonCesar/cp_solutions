#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int p, s;

    while((cin >> p >> s) && (p != 0 || s != 0)) {
        vector<int> player(p, 0);
        vector<bool> stopped(p, false);
        int t1, t2, t3, n, d1, d2, i = 0, ans = -1;
        cin >> t1 >> t2 >> t3 >> n;

        while(n--) {
            cin >> d1 >> d2;
            if (ans != -1) continue;
            while (stopped[i]) {
                stopped[i] = false;
                i = (i + 1) % p;
            }
            
            player[i] += d1 + d2;
            if (player[i] > s) {
                ans = i + 1;
            }
            if (player[i] == t1 || player[i] == t2 || player[i] == t3) {
                stopped[i] = true;
            }
            
            i = (i + 1) % p;
        }

        cout << ans << '\n';

    }

    return 0;
}
