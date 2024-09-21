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

int n, ans = 0;
vector<vector<int>> cows, g;
vector<bool> visited;

void bfs(int node) {
  visited[node] = true;
  for(int i = 0; i < (int) g[node].size(); i++)
      if(!visited[g[node][i]])
          bfs(g[node][i]);
}

int main(void) {
  mainIO("moocast");
  
  int n;
  cin >> n;

  cows.resize(n, vector<int>(3));

  for(int i = 0; i < n; i++)
      cin >> cows[i][0] >> cows[i][1] >> cows[i][2];

  g.resize(n);

  for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
          if(i != j && 
             ((cows[j][0] - cows[i][0]) * (cows[j][0] - cows[i][0]) +
             (cows[j][1] - cows[i][1]) * (cows[j][1] - cows[i][1])) <= 
             (cows[i][2] * cows[i][2]))
            g[i].push_back(j);
  
  for(int i = 0; i < n; i++) {
    visited.clear();
    visited.resize(n, false);
    bfs(i);
    int count = 0;

    for(int i = 0; i < n; i++) 
      count += visited[i];

    ans = max(ans, count);
  }

  cout << ans << '\n';
  
  return 0;
}