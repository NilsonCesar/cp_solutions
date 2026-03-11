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
    mainIO("paintbarn");
    int n, k, ans = 0;
    int x1, x2, y1, y2;
    cin >> n >> k;
    vector<vector<int>> grid(1010, vector<int>(1010, 0)), diff(1010, vector<int>(1010, 0));

    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        grid[x1 + 1][y1 + 1]++;
        grid[x1 + 1][y2 + 1]--;
        grid[x2 + 1][y1 + 1]--;
        grid[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i < 1002; i++) {
        for (int j = 1; j < 1002; j++) {
            diff[i][j] = grid[i - 1][j - 1] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    for (int i = 1; i < 1002; i++) {
        for (int j = 1; j < 1002; j++) {
            ans += (diff[i][j] == k);
        }
    }

    cout << ans << '\n';

    return 0;
}
