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
    int n, d = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        d++;
        int b = a[i];
        while (i < n && a[i] == b) i++;
        i--;
    }

    cout << d << '\n';

    for (int i = 0; i < n; i++) {
        int b = a[i];
        cout << a[i] << ' ';
        while (i < n && a[i] == b) i++;
        i--;
    }
    cout << '\n';

    return 0;
}