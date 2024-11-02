#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int h, w, k, ans;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void solve(int i, int j, int k_tmp) {
	if(i < 0 || i >= h || j < 0 || j >= w || visited[i][j] || grid[i][j] == '#') return;
	if(k == k_tmp) {
	    ans++;
	    return;
	}
	visited[i][j] = true;
	solve(i + 1, j, k_tmp + 1);
	solve(i - 1, j, k_tmp + 1);
	solve(i, j + 1, k_tmp + 1);
	solve(i, j - 1, k_tmp + 1);
	visited[i][j] = false;
}

int main(void) {
    mainIO();
    cin >> h >> w >> k;

    grid.resize(h, vector<char>(w));
    visited.resize(h, vector<bool>(w, false));

    for(int i = 0; i < h; i++)
	for(int j = 0; j < w; j++)
	    cin >> grid[i][j];

    for(int i = 0; i < h; i++)
	for(int j = 0; j < w; j++)
	    if(grid[i][j] == '.') {
		solve(i, j, 0);
		visited.clear();
		visited.resize(h, vector<bool>(w, false));
	    }
    
    cout << ans << '\n';
    return 0;
}
