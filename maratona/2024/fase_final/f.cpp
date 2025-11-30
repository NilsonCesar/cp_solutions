#include <bits/stdc++.h>

using namespace std;

void print(vector<char> ans, int n) {
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
}

int main(void) {
    int k, n;
    cin >> k >> n;

    if ((n + 1) / 2 < k) {
        cout << '*' << '\n';
        return 0;
    }

    vector<char> ans(n);

    for (int a = 0; a <= k; a++) {
        int b = k - a;
        if (b < 0) break;
        if (3 * a + 2 * b >= n) {
            for (int i = 0; i < min(3 * a, n); i += 3) {
                ans[i] = '-';
                ans[i + 1] = 'X';
                ans[i + 2] = '-';
            }

            for (int i = 3 * a; i < min(3 * a + 2 * b, n); i += 2) {
                ans[i] = 'X';
                ans[i + 1] = '-';
            }

            print(ans, n);
            return 0;
            
        }
    }

    cout << '*' << '\n';
    return 0;
} 