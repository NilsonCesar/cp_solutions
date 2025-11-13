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
    string tmp;
    cin >> n >> m;

    vector<vector<char>> cons(n, vector<char>(m)), mike(n, vector<char>(m)), uni(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cons[i][j];
        }
    }

    getline(cin, tmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mike[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cons[i][j] == '.' && mike[i][j] == '.') {
                uni[i][j] = '.';
            } else {
                uni[i][j] = '#';
            }
        }
    }

    vector<vector<int>> gc(n, vector<int>(m, 1e7)), gm(n, vector<int>(m, 1e7)), gu(n, vector<int>(m, 1e7));

    vector<vector<bool>> visitedc(n, vector<bool>(m, false)), visitedm(n, vector<bool>(m, false)), visitedu(n, vector<bool>(m, false));

    queue<vector<int>> to_visit;
    to_visit.push({0, 0, 0});

    while (!to_visit.empty()) {
        vector<int> node = to_visit.front();
        int i = node[0], j = node[1], d = node[2];
        to_visit.pop();

        if (i == n - 1 && j == m - 1) gc[i][j] = min(d, gc[i][j]);
        if (visitedc[i][j]) continue;
        visitedc[i][j] = true;
        gc[i][j] = min(d, gc[i][j]);

        if (i - 1 >= 0 && cons[i - 1][j] != '#') {
            to_visit.push({i - 1, j, d + 1});
        }

        if (i + 1 < n && cons[i + 1][j] != '#') {
            to_visit.push({i + 1, j, d + 1});
        }

        if (j - 1 >= 0 && cons[i][j - 1] != '#') {
            to_visit.push({i, j - 1, d + 1});
        }

        if (j + 1 < m && cons[i][j + 1] != '#') {
            to_visit.push({i, j + 1, d + 1});
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << gc[i][j];
    //     }
    //     cout << '\n';
    // }

    to_visit.push({0, 0, 0});

    while (!to_visit.empty()) {
        vector<int> node = to_visit.front();
        int i = node[0], j = node[1], d = node[2];
        to_visit.pop();

        if (i == n - 1 && j == m - 1) gm[i][j] = min(d, gm[i][j]);
        if (visitedm[i][j]) continue;
        visitedm[i][j] = true;
        gm[i][j] = min(d, gm[i][j]);

        if (i - 1 >= 0 && mike[i - 1][j] != '#') {
            to_visit.push({i - 1, j, d + 1});
        }

        if (i + 1 < n && mike[i + 1][j] != '#') {
            to_visit.push({i + 1, j, d + 1});
        }

        if (j - 1 >= 0 && mike[i][j - 1] != '#') {
            to_visit.push({i, j - 1, d + 1});
        }

        if (j + 1 < m && mike[i][j + 1] != '#') {
            to_visit.push({i, j + 1, d + 1});
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << gm[i][j];
    //     }
    //     cout << '\n';
    // }

    to_visit.push({0, 0, 0});

    while (!to_visit.empty()) {
        vector<int> node = to_visit.front();
        int i = node[0], j = node[1], d = node[2];
        to_visit.pop();

        if (i == n - 1 && j == m - 1) gu[i][j] = min(d, gu[i][j]);
        if (visitedu[i][j]) continue;
        visitedu[i][j] = true;
        gu[i][j] = min(d, gu[i][j]);

        if (i - 1 >= 0 && uni[i - 1][j] != '#') {
            to_visit.push({i - 1, j, d + 1});
        }

        if (i + 1 < n && uni[i + 1][j] != '#') {
            to_visit.push({i + 1, j, d + 1});
        }

        if (j - 1 >= 0 && uni[i][j - 1] != '#') {
            to_visit.push({i, j - 1, d + 1});
        }

        if (j + 1 < m && uni[i][j + 1] != '#') {
            to_visit.push({i, j + 1, d + 1});
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << gu[i][j];
    //     }
    //     cout << '\n';
    // }

    cout << (gu[n - 1][m - 1] != 1e7 && gu[n - 1][m - 1] == gc[n - 1][m - 1] && gu[n - 1][m - 1] == gm[n - 1][m - 1] ? "YES" : "NO") << '\n';

    return 0;
}
