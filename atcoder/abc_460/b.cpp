#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    cin >> t;

    while(t--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long long d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if (d2 <= (r1 + r2) * (r1 + r2)) {
            if (d2 <= max(r1, r2) * max(r1, r2) && d2 >= (r2 - r1) * (r2 - r1)) {
                cout << "Yes";
            } else if (d2 > max(r1, r2) * max(r1, r2)) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        } else {
            cout << "No";
        }
        cout << '\n';
    }

    return 0;
}
