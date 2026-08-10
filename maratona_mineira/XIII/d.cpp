#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(void) {_
    int d, m;
    cin >> d >> m;

    if (d == m) {
        cout << "DATA SEGURA";
    } else if ((d > 12 && m <= 12) || (d <= 12 && m > 12)) {
        cout << "DATA SEGURA";
    } else {
        cout << "DATA INCERTA";
    }
    cout << '\n';

    return 0;
}