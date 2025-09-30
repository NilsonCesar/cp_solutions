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
    if (n < 5) cout << 0;
    else if (n <= 9) cout << 1;
    else cout << 2 * (n / 10);
    cout << '\n'; 
    return 0;
}
