#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int t, n, a, b;
    cin >> t;

    while(t--) {
        cin >> n >> a >> b;
        vector<int> A, B;

        if (a + b > n) {
            cout << "NO" << '\n';
            continue;
        } else {
            int q = a + b;
            for (int i = 1; i <= q; i++)
                A.push_back(i);
            for (int i = q - b + 1; i <= q; i++)
                B.push_back(i);
            for (int i = 1; i <= q - b; i++)
                B.push_back(i);
            for (int i = q + 1; i <= n; i++) {
                A.push_back(i);
                B.push_back(i);
            }
        }

        int c_a = 0, c_b = 0;

        for (int i = 0; i < n; i++) {
            c_a += A[i] > B[i];
            c_b += A[i] < B[i];
        }

        if (c_a == a && c_b == b) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++)
                cout << A[i] << ' ';
            cout << '\n';
            for (int i = 0; i < n; i++)
                cout << B[i] << ' ';
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
