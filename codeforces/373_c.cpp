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
    int n;
    cin >> n;
    int v = n;
    vector<int> a(n);
    vector<bool> held(n, false);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = n / 2 - 1, j = n - 1;
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n';

    while(i >= 0 && j >= 0) {
        // cout << i << ' ' << j << ' ' << v << '\n';
        if (a[i] * 2 <= a[j]) {
            held[i] = true;
            j--;
            v--;
        }
        i--;
    }

    cout << v << '\n';

    return 0;
}
