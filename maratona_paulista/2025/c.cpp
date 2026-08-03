#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);

int main(void) {_
    int n, x, y;
    cin >> n;

    while(n--) {
        cin >> x >> y;

        if (y >= 0) {
            if (-200 <= x && x <= -100) {
                x -= -200;
                if (y <= x) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else if (-100 <= x && x <= 0) {
                if (y <= 100) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else if (0 <= x && x <= 100) {
                if (100 - x >= y) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else if (100 <= x && x <= 200) {
                if (y == 0) {
                    cout << "S";
                } else {
                    cout << "N";
                }
            } else {
                cout << 'N';
            }

            cout << '\n';
        } else {
            if (-100 <= x && x <= 0) {
                if (-100 - x <= y) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else if (0 <= x && x <= 100) {
                if (y >= -100) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else if (100 <= x && x <= 200) {
                x -= 100;
                if (y >= x - 100) {
                    cout << 'S';
                } else {
                    cout << 'N';
                }
            } else {
                cout << 'N';
            }

            cout << '\n';
        }
    }
}