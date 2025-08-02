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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    for (int i = a; i < n - b; i++) cout << s[i];
    cout << '\n';

    return 0;
}
