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

int n, m;
vector<vector<int>> g;
vector<int> sg;
vector<int> labels, visited;

void dfs(int u, int label) {
  for (int i = 0; i < (int)g[u].size(); i++)
    if (!visited[g[u][i]]) {
      visited[g[u][i]] = 1;
      dfs(g[u][i], label);
    }
}

int main(void) {
  mainIO();
  cin >> n >> m;
  g.resize(n + 1, vector<int>());
  labels.resize(n + 1);
  visited.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int act_label = 0;

  for (int i = 1; i <= n; i++)
    if (!visited[i]) {
      visited[i] = 1;
      act_label++;
      sg.push_back(i);
      dfs(i, act_label);
    }

  cout << act_label - 1 << '\n';

  if(n == 1) return 0;

  for(int i = 1; i < (int) sg.size(); i++) 
    cout << sg[i - 1] << ' ' << sg[i] << '\n';
  return 0;
}
