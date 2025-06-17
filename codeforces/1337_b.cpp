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
        int x, n, m;
        cin >> x >> n >> m;
        while(x > 20 && n-- > 0) x = x / 2 + 10;
        x -= m * 10; 
        cout << (x <= 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}