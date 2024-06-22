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
    long long sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    
    sx -= abs(sy - sx) % 2;
    tx -= abs(ty - tx) % 2;

    tx -= sx;
    ty -= sy;

    tx = abs(tx);
    ty = abs(ty);

    cout << ty + max(0ll, tx - ty) / 2 << '\n';

    return 0;
}
