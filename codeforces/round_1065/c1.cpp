#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100000+7

int main(void) {_
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n + 1), B(n + 1), suf(n + 2), a(n + 1), b(n + 1);
        suf[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            a[i] = A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
            b[i] = B[i];
        }

        suf[n] = a[n];
        for (int i = n - 1; i > 0; i--) {
            suf[i] = a[i] ^ suf[i + 1];
        }

        int accA;

        for (int i = 2; i <= n; i++) {
            if (i == 2) {
                accA = a[i - 1] ^ a[i];
                if (accA ^ suf[i + 1] == 0) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                    accA = b[i - 1] ^ b[i];
                }
            } else if (i % 2) {
                int prevAcc = accA ^ a[i - 1];
                accA = prevAcc ^ a[i];
                if (accA ^ suf[i + 1] == 0) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                    accA = prevAcc ^ a[i];
                }
            } else {
                if (accA ^ suf[i]) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                }
            }
        }

        if (n % 2 == 0) {
            accA = accA ^ a[n];
        }

        int accB = b[1];
        suf[n] = b[n];
        for (int i = 1; i <= n; i++) {
            a[i] = A[i];
            b[i] = B[i];
        }

        for (int i = n - 1; i > 0; i--) {
            suf[i] = b[i] ^ suf[i + 1];
        }
    
        for (int i = 2; i <= n; i++) {
            if (i == 2) {
                accB = b[i - 1] ^ b[i];
                if (accB ^ suf[i + 1] == 0) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                    accB = b[i - 1] ^ b[i];
                }
            } else if (i % 2 == 0) {
                int prevAcc = accB ^ b[i - 1];
                accB = prevAcc ^ b[i];
                if (accB ^ suf[i + 1] == 0) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                    accB = prevAcc ^ b[i];
                }
            } else {
                if (accB ^ suf[i]) {
                    int c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                }
            }
        }

        if (n % 2 == 1) {
            accB = accB ^ b[n];
        }

        cout << accA << ' ' << accB << '\n';

        if (accA > accB) cout << "Ajisai";
        else if (accB > accA) cout << "Mai";
        else cout << "Tie";
        cout << '\n';
    }

    return 0;
}
