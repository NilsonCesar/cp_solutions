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
    int t;
    char op1, op2;
    cin >> t;
    while (t--) {
        int n, m, w = 0, b = 0;
        op1 = 'B', op2 = 'W';
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = j % 2 ? op2 : op1;
                grid[i][j] == 'W' ? w++ : b++;
            }
            op1 = grid[i][0] == 'B' ? 'W' : 'B';
            op2 = op1 == 'B' ? 'W' : 'B';
        }

        if (b != w + 1) {
            if (grid[n - 1][m - 1] == 'W') grid[n - 1][m - 1] = 'B';
            else grid[n - 1][m - 2] = 'B';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                cout << grid[i][j];
            cout << '\n';
        }
    }

    return 0;
}
