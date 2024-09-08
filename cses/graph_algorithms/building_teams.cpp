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
vector<int> team;

void dfs(int u, int t) {
  for (int i = 0; i < (int) g[u].size(); i++) {
    if (!team[g[u][i]]) {
      team[g[u][i]] = (t % 2) + 1;
      dfs(g[u][i], (t % 2) + 1);
    } else if (team[g[u][i]] == t) {
      cout << "IMPOSSIBLE" << endl;
      exit(0);
    }
  }
}

int main(void) {
  mainIO();

  cin >> n >> m;
  g.resize(n + 1, vector<int>());
  team.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    if (!team[i]) {
      // cout << "here " << i << '\n';
      team[i] = 1;
      dfs(i, 1);
      // for (int i = 1; i <= n; i++)
      //   cout << team[i] << ' ';
      // cout << '\n';
    }

  for (int i = 1; i <= n; i++)
    cout << team[i] << ' ';
  cout << '\n';

  return 0;
}
