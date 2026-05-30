#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 1000000010
#define MAXN 100007

int main(void) {_
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid1(h, vector<char>(w)), grid2(h, vector<char>(w, '.'));
    queue<vector<int>> q;

    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) 
            cin >> grid1[i][j];

    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) {
            if (grid1[i][j] == '#') {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x < 0 || x >= h) continue;
                        if (y < 0 || y >= w) continue;
                        if (x == i && y == j) continue;

                        if (grid1[x][y] == '.') grid2[x][y] = '#';
                    }
                }
            }
        }
    
    vector<vector<int>> dist(h, vector<int>(w, INF));
    grid1 = move(grid2);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid1[i][j] == '#') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    

    while(!q.empty()) {
        int i = q.front()[0], j = q.front()[1];
        q.pop();
        for (int x = i - 1; x <= i + 1; x++) {
            for (int y = j - 1; y <= j + 1; y++) {
                if (x == i && y == j) continue;
                if (x < 0 || x >= h) continue;
                if (y < 0 || y >= w) continue;

                if (dist[x][y] == INF) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (dist[i][j] % 2 == 0 ? '.' : '#');
        }
        cout << '\n';
    }

    return 0;
}
