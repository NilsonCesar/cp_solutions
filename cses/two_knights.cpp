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
    long long n, i = 2;
    cin >> n;
    cout << 0 << '\n';
    if (n >= 2) {
        cout << 6 << '\n';
        i++;
    }
    for (; i <= n; i++) {
        long long catcheable = 2 * (2 * (i - 2) + 2 * (i - 2) * (i - 2));
        cout << (i * i) * (i * i - 1) / 2 - catcheable << '\n';
    }


    return 0;
}
