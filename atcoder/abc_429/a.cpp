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
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cout << (i <= m ? "OK" : "Too Many Requests") << '\n';
    }

    return 0;
}
