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
    int n, minI, minJ;
    cin >> n;
    int grid[101][101] = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            minI = 0, minJ = 0;
            vector<int> vec;

            for (int k = 0; k < i; k++) vec.push_back(grid[k][j]);
            sort(vec.begin(), vec.end());
            for (int k = 0; k < (int) vec.size(); k++)
                minI += vec[k] == minI;
            for (int k = 0; k < j; k++) vec.push_back(grid[i][k]);
            sort(vec.begin(), vec.end());
            for (int k = 0; k < (int) vec.size(); k++)
                minJ += vec[k] == minJ;
            grid[i][j] = max(minI, minJ);
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
