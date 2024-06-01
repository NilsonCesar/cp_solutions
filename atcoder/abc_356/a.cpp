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
    mainIO("");
    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 1; i < l; i++)
        cout << i << ' ';
    
    for(int i = r; i >= l; i--)
        cout << i << ' ';
    
    for(int i = r + 1; i <= n; i++)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
