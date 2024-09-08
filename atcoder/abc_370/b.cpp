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
    int n, ans;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];

    ans = a[1][1];
    for(int i = 2; i <= n; i++) {
        if(ans < i) ans = a[i][ans];
        else ans = a[ans][i];  
    }

    cout << ans << '\n';

    return 0;
}
