#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main (void) {_
    int n;
    char q;
    cin >> n >> q;

    if (q == 'Q') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << '*';
            cout << '\n';
        }
    } else {
        int s = 1;
        int blank = n - s;
        int mid = blank / 2;
        while (s < n) {
            for (int i = 0; i < mid; i++) {
                cout << ' ';
            }
            for (int i = 0; i < s; i++) {
                cout << "*";
            }
            for (int i = 0; i < mid; i++) {
                cout << ' ';
            }
            cout << '\n';
            s += 2;
            blank = n - s;
            mid = blank / 2;
        }
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << '\n';
        s = n - 2;
        blank = n - s;
        mid = blank / 2;
        while (s > 0) {
            for (int i = 0; i < mid; i++) {
                cout << ' ';
            }
            for (int i = 0; i < s; i++) {
                cout << "*";
            }
            for (int i = 0; i < mid; i++) {
                cout << ' ';
            }
            cout << '\n';
            s -= 2;
            blank = n - s;
            mid = blank / 2;
        }
    }

    return 0;
}
