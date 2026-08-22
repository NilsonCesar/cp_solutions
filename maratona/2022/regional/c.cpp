#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n;
vector<vector<bool>> visited(2005, vector<bool>(2005, false));

int main(void) {_
    cin >> n;
    n++;
    int xi, yi;
    cin >> xi >> yi;
    xi *= 2;
    yi *= 2;
    
    for (int i = 1; i < n; i++) {
        int xf, yf;
        cin >> xf >> yf;
        xf *= 2;
        yf *= 2;

        if (xi == xf) {
            for (int y = min(yi, yf); y <= max(yi, yf); y++) {
                visited[xi][y] = true;
            }
        } else {
            for (int x = min(xi, xf); x <= max(xi, xf); x++) {
                visited[x][yi] = true;
            }
        }
        xi = xf;
        yi = yf;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (x - 1 >= 0) q.push({x - 1, y});
        if (x + 1 < 2005) q.push({x + 1, y});
        if (y - 1 >= 0) q.push({x, y - 1});
        if (y + 1 < 2005) q.push({x, y + 1});
    }

    int ans = 0;
    for (int i = 0; i < 2005; i++) {
        for (int j = 0; j < 2005; j++) {
            if (visited[i][j]) continue;
            int tmp_ans = 0;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (visited[x][y]) continue;
                if (x % 2 == 1 && y % 2 == 1) tmp_ans++;
                visited[x][y] = true;
                if (x - 1 >= 0) q.push({x - 1, y});
                if (x + 1 < 2005) q.push({x + 1, y});
                if (y - 1 >= 0) q.push({x, y - 1});
                if (y + 1 < 2005) q.push({x, y + 1});
            }

            ans = max(ans, tmp_ans);
        }
    }

    cout << ans << '\n';


    return 0;
}
