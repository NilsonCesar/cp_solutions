#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    bool eq = true;
    for (int i = 0; i < 3 * n; i += 3) {
        if (a[i] != a[i + 1] || a[i + 1] != a[i + 2]) {
            eq = false;
            break;
        }
    }

    cout << (eq ? 'N' : 'Y') << '\n';
}