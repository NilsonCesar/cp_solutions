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
    mainIO("bcount");
    int n, q, l, r;
    cin >> n >> q;
    vector<vector<int>> cows(3, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++) {
        cin >> l;
        for(int j = 0; j < 3; j++)
            cows[j][i] = (l - 1 == j) + cows[j][i - 1];
    }

    for(int i = 0; i < q; i++) {
        cin >> l >> r;

        cout << cows[0][min(r, n)] - cows[0][max(l - 1, 0)];
        for(int j = 1; j < 3; j++)
            cout << ' ' << cows[j][min(r, n)] - cows[j][max(l - 1, 0)];
        cout << '\n';
    }

    return 0;
}
