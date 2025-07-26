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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    bool ans = true;
    for (int i = l - 1; i <= r - 1; i++) 
        if (s[i] == 'x')
            ans = false;
    
    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
