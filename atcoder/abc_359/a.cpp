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
    int n, ans = 0;
    string s;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "Takahashi") ans++;
    }

    cout << ans << '\n';

    return 0;
}
