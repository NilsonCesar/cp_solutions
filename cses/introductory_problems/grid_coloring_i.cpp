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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<char> pos = {'A', 'B', 'C', 'D'};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map<char, bool> valid;
            valid['A'] = true;
            valid['B'] = true;
            valid['C'] = true;
            valid['D'] = true;

            if (i - 1 >= 0) {
                valid[grid[i - 1][j]] = false;
            }
            if (j - 1 >= 0) {
                valid[grid[i][j - 1]] = false;
            }
            valid[grid[i][j]] = false;

            bool is_valid = false;
            for (char c : pos) {
                if (valid[c]) {
                    grid[i][j] = c;
                    is_valid = true;
                    break;
                }
            }

            if (!is_valid) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << grid[i][j];
        cout << '\n';
    }

    return 0;
}
