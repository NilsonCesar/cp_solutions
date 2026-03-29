#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios_base::sync_with_stdio(0);

int main() {_
    int t, d, m;
    cin >> t >> d >> m;
    int y1 = 0, y2, valid = false;

    for (int i = 0; i < m; i++) {
        cin >> y2;
        valid = valid || (y2 - y1 >= t);
        y1 = y2;
    }
    valid = valid || (d - y1 >= t);

    cout << (valid ? "Y" : "N") << '\n';

    return 0;
}