#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w)), ans;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    ans = grid;

    bool canRemove = true;

    while(canRemove) {
        // top
        bool top = true;
        for (int j = 0; j < (int) ans[0].size(); j++) {
            if (ans[0][j] == '#') top = false;
        }

        if (top) {
            vector<vector<char>> tmp;
            for (int i = 1; i < (int) ans.size(); i++) {
                tmp.push_back(vector<char>());
                for (int j = 0; j < (int) ans[0].size(); j++) {
                    tmp[i - 1].push_back(ans[i][j]);
                }
            }

            ans = tmp;
            continue;
        }

        // bottom
        bool bottom = true;
        for (int j = 0; j < (int) ans[0].size(); j++) {
            if (ans[(int) ans.size() - 1][j] == '#') bottom = false;
        }

        if (bottom) {
            vector<vector<char>> tmp;
            for (int i = 0; i < (int) ans.size() - 1; i++) {
                tmp.push_back(vector<char>());
                for (int j = 0; j < (int) ans[0].size(); j++) {
                    tmp[i].push_back(ans[i][j]);
                }
            }

            ans = tmp;
            continue;
        }

        // left
        bool left = true;
        for (int i = 0; i < (int) ans.size(); i++) {
            if (ans[i][0] == '#') left = false;
        }

        if (left) {
            vector<vector<char>> tmp;
            for (int i = 0; i < (int) ans.size(); i++) {
                tmp.push_back(vector<char>());
                for (int j = 1; j < (int) ans[0].size(); j++) {
                    tmp[i].push_back(ans[i][j]);
                }
            }
            ans = tmp;
            continue;
        }

        // right
        bool right = true;
        for (int i = 0; i < (int) ans.size(); i++) {
            if (ans[i][(int) ans[0].size() - 1] == '#') right = false;
        }

        if (right) {
            vector<vector<char>> tmp;
            for (int i = 0; i < (int) ans.size(); i++) {
                tmp.push_back(vector<char>());
                for (int j = 0; j < (int) ans[0].size() - 1; j++) {
                    tmp[i].push_back(ans[i][j]);
                }
            }

            ans = tmp;
            continue;
        }

        canRemove = false;
    }

    for (int i = 0; i < (int) ans.size(); i++) {
        for (int j = 0; j < (int) ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
