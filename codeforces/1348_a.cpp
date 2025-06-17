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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a = 0, b = (1 << n);
        for (int i = n - 1; i > n / 2 - 1; i--) a += (1 << i);
        for (int i = 1; i < n / 2; i++) b += (1 << i);

        cout << b - a << '\n';
    }

    return 0;
}