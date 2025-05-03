#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<char>> copyMatrix(vector<vector<char>> m) {
    int n = (int) m.size();
    vector<vector<char>> c(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i][j] = m[i][j];
    return c;
} 

int main(void) {
    mainIO();
    int ans = 1e5, n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n)), t(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> t[i][j];

    for(int i = 0; i < 4; i++) {
        int tmpAns = i;
        for (int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) 
                tmpAns += s[j][k] != t[j][k];
        ans = min(ans, tmpAns);

        vector<vector<char>> copyS = copyMatrix(s);

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                s[k][n - j - 1] = copyS[j][k];
    }

    cout << ans << '\n';

    return 0;
}