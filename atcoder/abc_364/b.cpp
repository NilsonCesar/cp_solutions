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
    int h, w, x, y;
    string s;
    cin >> h >> w >> x >> y;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1));

    for(int i = 1; i <= h; i++) 
        for(int j = 1; j <= w; j++) 
            cin >> grid[i][j];

    cin >> s;

    for(char c : s) {
        if(c == 'U') 
            if(x - 1 >= 1 && grid[x - 1][y] != '#') 
                x--;
        if(c == 'D')
            if(x + 1 <= h && grid[x + 1][y] != '#')
                x++;
        if(c == 'L')
            if(y - 1 >= 1 && grid[x][y - 1] != '#')
                y--;
        if(c == 'R')
            if(y + 1 <= w && grid[x][y + 1] != '#')
                y++;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
