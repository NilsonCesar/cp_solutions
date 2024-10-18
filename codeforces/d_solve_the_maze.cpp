#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

bool can;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited, visitedCopy, visitedB, visitedG;
vector<vector<int>> bad, good;

bool invalid(int i, int j) {
    return i < 0 || i >= n || j < 0 || j >= m;
}

void block(int i, int j) {
    if(invalid(i, j) || visited[i][j]) return;
    if(grid[i][j] == '.') {
        visited[i][j] = true;
        grid[i][j] = '#';
    }
}

void floodfill(int i, int j) {
    if(invalid(i, j) || visitedCopy[i][j]) return;
    
    visitedCopy[i][j] = true;
    if(i == n - 1 && j == m -1) {
        can = true;
        return;
    }
    
    floodfill(i - 1, j);
    floodfill(i + 1, j);
    floodfill(i, j - 1);
    floodfill(i, j + 1);
}

void floodfillAlt(int i, int j, int flip) {
    if(invalid(i, j) || (!flip && visitedB[i][j])) return;
    if(flip && visitedG[i][j]) return;
    if(grid[i][j] == '#') return;
    
    if(!flip) visitedB[i][j] = true;
    else visitedG[i][j] = true;
    
    
    floodfillAlt(i - 1, j, flip);
    floodfillAlt(i + 1, j, flip);
    floodfillAlt(i, j - 1, flip);
    floodfillAlt(i, j + 1, flip);
}

int main(void) {
    mainIO();
    int t;
    cin >> t;
    while(t--) {
        bool pass = false;
        cin >> n >> m;
        grid.resize(n, vector<char>(m));
        visited.resize(n, vector<bool>(m, true));
        visitedB.resize(n, vector<bool>(m, false));
        visitedG.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == '.' || grid[i][j] == 'G' || grid[i][j] == 'B') visited[i][j] = false;
                if(grid[i][j] == 'G') good.push_back({i, j});
                if(grid[i][j] == 'B') bad.push_back({i, j});
            }
        }
        
        for(int i = 0; i < (int) bad.size(); i++) {
            can = false;
            block(bad[i][0] - 1, bad[i][1]);
            block(bad[i][0] + 1, bad[i][1]);
            block(bad[i][0], bad[i][1] - 1);
            block(bad[i][0], bad[i][1] + 1);
        }
        
        visitedCopy = visited;
        for(int i = 0; i < (int) bad.size(); i++) {
            int ii = bad[i][0], jj = bad[i][1];
            if(visitedB[ii][jj]) continue;
            floodfill(bad[i][0], bad[i][1]);
            if(can) {
                cout << "No";
                pass = true;
                break;
            }
            floodfillAlt(ii, jj, 0);
        }
        
        visitedCopy = visited;
        for(int i = 0; !pass && i < (int) good.size(); i++) {
            int ii = good[i][0], jj = good[i][1];
            if(visitedG[ii][jj]) continue;
            can = false;
            floodfill(good[i][0], good[i][1]);
            if(!can) {
                cout << "No";
                pass = true;
                break;
            }
            floodfillAlt(ii, jj, 1);
        }
        
        if(!pass) cout << "Yes";
        cout << '\n';
        
        grid.clear();
        visited.clear();
        good.clear();
        bad.clear();
        visitedB.clear();
        visitedG.clear();
    }
    
    return 0;
}
