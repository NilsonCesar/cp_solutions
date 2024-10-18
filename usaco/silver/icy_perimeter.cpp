#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m, dia, area, ansDia, ansArea;
vector<vector<bool>> visited;
vector<vector<char>> grid;

bool invalid_move(int i, int j) {
    return i < 0 || i >= n || j < 0 || j >= m;
}

void floodfill(int i, int j) {
    if(invalid_move(i, j) || visited[i][j]) return;
    visited[i][j] = true;
    area++;
    if(invalid_move(i - 1, j) || grid[i - 1][j] == '.') dia++;
    if(invalid_move(i + 1, j) || grid[i + 1][j] == '.') dia++;
    if(invalid_move(i, j - 1) || grid[i][j - 1] == '.') dia++;
    if(invalid_move(i, j + 1) || grid[i][j + 1] == '.') dia++;
    floodfill(i - 1, j);
    floodfill(i + 1, j);
    floodfill(i, j - 1);
    floodfill(i, j + 1);
}

int main(void) {
    mainIO("perimeter");
    cin >> n;
    m = n;
    visited.resize(n, vector<bool>(m, true));
    grid.resize(n, vector<char>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '#') visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) continue;
            dia = area = 0;
            floodfill(i, j);
            if(area > ansArea) {
                ansArea = area;
                ansDia = dia;
            } else if(area == ansArea && dia < ansDia) ansDia = dia;
        }
    }
    
    cout << ansArea << ' ' << ansDia << '\n';

    return 0;
}
