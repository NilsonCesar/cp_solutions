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

vector<vector<int>> g;
vector<bool> visited;

void dfs(int u, int v) {
  visited[u] = true;
  for(int i = 0; i < (int) g[u].size(); i++)
    if(!visited[g[u][i]] && g[u][i] != v)
        dfs(g[u][i], u);
}

int main(void) {
  mainIO();
  int p, c;
  while((cin >> p >> c) && (p != 0 || c != 0)) {
    g.resize(p, vector<int>());
    bool can = true;
    vector<pair<int, int>> e(c);

    for(int i = 0; i < c; i++) {
      cin >> e[i].first >> e[i].second;
      g[e[i].first].push_back(e[i].second);
      g[e[i].second].push_back(e[i].first);
    }

    for(int i = 0; i < c; i++) {
      visited.resize(p, false);
      dfs(e[i].first, e[i].second);
      for(int i = 0; i < p; i++)
          if(!visited[i])
            can = false;
      visited.clear();
    }

    if(can) cout << "No";
    else cout << "Yes";
    cout << '\n';
    
    g.clear();
    visited.clear();
  }

  return 0;
}