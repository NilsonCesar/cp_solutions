#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1, '.'));

    vector<pair<int, int>> end = {{1, w}, {h, w}, {h, 1}, {h, w}};

    for (int k = 0; k < 4; k++) {
        if (k < 2) {
            int i = end[k].first;
            for (int j = 1; j <= end[k].second; j++) {
                grid[i][j] = '#';
            }
        } else {
            int j = end[k].second;
            for (int i = 1; i <= end[k].first; i++) {
                grid[i][j] = '#';
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
