#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    if (cin >> t) {
        while (t--) {
            int p;
            char a, c;
            cin >> p;
            
            int r = 0, g = 0, b = 0;
            
            for (int i = 0; i < p; i++) {
                cin >> a >> c;

                if (a == 'G' && c == 'B') {
                    g += 2;
                } else if (a == 'G' && c == 'R') {
                    g += 1;
                } else if (a == 'R' && c == 'G') {
                    r += 2;
                } else if (a == 'R' && c == 'B') {
                    r += 1;
                } else if (a == 'B' && c == 'G') {
                    b += 1;
                } else if (a == 'B' && c == 'R') {
                    b += 2;
                }
            }
            
            int maxn = max(r, max(g, b));
            int minn = min(r, min(g, b));
            int mid = r + g + b - maxn - minn;

            if (maxn == minn) cout << "trempate";
            else if (maxn == mid) cout << "empate";
            else {
                if (maxn == r) cout << "red";
                else if (maxn == g) cout << "green";
                else cout << "blue";
            }
            cout << '\n';
        }
    }

    return 0;
}