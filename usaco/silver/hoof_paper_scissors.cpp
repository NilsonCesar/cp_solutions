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
    mainIO("hps");
    int n, ans = 0;
    char c;
    cin >> n;
    vector<vector<int>> sumprefs(3, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(c == 'P') sumprefs[0][i] = 1;
        if(c == 'H') sumprefs[1][i] = 1;
        if(c == 'S') sumprefs[2][i] = 1;
        for(int j = 0; j < 3; j++)
            sumprefs[j][i] += sumprefs[j][i - 1];
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i != j)
                for(int x = 0; x <= n; x++) 
                    ans = max(ans, sumprefs[j][n] - sumprefs[j][x] + sumprefs[i][x]);
    cout << ans << '\n';
 
    return 0;
}