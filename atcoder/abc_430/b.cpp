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
    set<vector<vector<char>>> s;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j  < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            vector<vector<char>> comb;
            // cout << "COMB:" << '\n';
            for (int k = i; k < i + m; k++) {
                vector<char> tmp;
                for (int l = j; l < j + m; l++) {
                    tmp.push_back(grid[k][l]);
                    // cout << grid[k][l];
                }
                // cout << '\n';
                comb.push_back(tmp);
            }
            s.insert(comb);
        }
    }

    cout << (int) s.size() << '\n';

    return 0;
}
