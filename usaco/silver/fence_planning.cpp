#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  if (s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int x_min, x_max, y_min, y_max;
vector<bool> visited;
vector<vector<int>> g, cords;

void bfs(int node) {
  visited[node] = true;
  x_min = min(x_min, cords[node][0]);
  x_max = max(x_max, cords[node][0]);
  y_min = min(y_min, cords[node][1]);
  y_max = max(y_max, cords[node][1]);
  for(int i = 0; i < (int) g[node].size(); i++)
    if(!visited[g[node][i]])
      bfs(g[node][i]);
}

int main(void) {
  mainIO("fenceplan");
  int n, m, u, v, ans = 1e9;
  cin >> n >> m;
  g.resize(n + 1);
  visited.resize(n + 1, false);

  cords.resize(n + 1, vector<int>(2));

  for(int i = 1; i <= n; i++) 
    cin >> cords[i][0] >> cords[i][1];

  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    if(visited[i]) continue;
    x_min = y_min = 1e9;
    x_max = y_max = -1e9;
    bfs(i);
    ans = min(ans, 2 * (x_max - x_min) + 2 * (y_max - y_min));
  }

  cout << ans << '\n';
  
  return 0;
}