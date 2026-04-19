#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int l, k;
    cin >> l >> k;
    int c;
    c = l;
    l = min(l, k);
    k = max(k, c);

    if (l <= 8 && k >= 9) {
        cout << "final";
    } else {
        l = l % 8;
        k = k % 8;
        if (l == 0) l = 8;
        if (k == 0) k = 8;

        if (l <= 4 && k >= 5) {
            cout << "semifinal";
        } else {
            l = l % 4;
            k = k % 4;

            if (l == 0) l = 4;
            if (k == 0) k = 4;

            if (l <= 2 && k >= 3) {
                cout << "quartas";
            } else {
                cout << "oitavas";
            }
        }
        
    }
    cout << '\n';

    return 0;
}
