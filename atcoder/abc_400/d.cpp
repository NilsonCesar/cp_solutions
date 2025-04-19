#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<bool>> visited;
vector<vector<char>> grid;
int min_dist_i = 10e8, min_dist_j = 10e8, a, b, c, d, h, w;


void visit(int i, int j) {
    if(visited[i][j]) return;
    int dist = abs(c - i) + abs(d - j);
    if (dist < min_dist_i + min_dist_j) {
	    min_dist_i = abs(c - i);
	    min_dist_j = abs(d - j);
	    cout << i << ' ' << j << '\n';
    }
    visited[i][j] = true;
    if (i - 1 > 0 and grid[i - 1][j] == '.') visit(i - 1, j);
    if (i + 1 <= h and grid[i + 1][j] == '.') visit(i + 1, j);
    if (j - 1 > 0 and grid[i][j - 1] == '.') visit(i, j - 1);
    if (j + 1 <= w and grid[i][j + 1] == '.') visit(i, j + 1);
}

int main(void) {
    // mainIO();
    cin >> h >> w;
    grid.resize(h + 1, vector<char>(w + 1));
    visited.resize(h + 1, vector<bool>(w + 1));
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
	    cin >> grid[i][j];
    cin >> a >> b >> c >> d;
    visit(a, b);
    int ans = 0;
    if (min_dist_i == 0) ans = (min_dist_j - 1) / 2 + (min_dist_j - 1) % 2;
    else if (min_dist_j == 0) ans = (min_dist_i - 1) / 2 + (min_dist_i - 1) % 2;
    else if (min_dist_i == 1 and min_dist_j == 1) ans = 1; 
    else ans = (min_dist_i - 1) / 2 + (min_dist_i - 1) % 2 + (min_dist_j - 1) / 2 + (min_dist_j - 1) % 2;

    cout << ans << '\n';
    return 0;
}
