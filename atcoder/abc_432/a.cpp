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
    int a, b, c;
    cin >> a >> b >> c;
    int tmp = a + b + c;
    int tmp1 = a;
    a = min(a, min(b, c));
    c = max(tmp1, max(b, c));
    b = tmp - a - c;
    cout << c << b << a << '\n';

    return 0;
}
