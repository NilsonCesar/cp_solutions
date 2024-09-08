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
vector<int> closed;
vector<int> labels;

void dfs(int u, int l) {
  // cout << u << ' ' <<  l << '\n';
  if(u < 1 || u > n) return;
  for (int i = 0; i < (int) g[u].size(); i++)
    if (!labels[g[u][i]] && labels[g[u][i]] != -1) {
      labels[g[u][i]] = l;
      dfs(g[u][i], l);
    }
}

bool check_connected() {
  int act_label = 0;
  labels = vector<int>(n + 1, 0);
  for (int i = 0; i < (int)closed.size(); i++)
    labels[closed[i]] = -1;
  for (int i = 1; i <= n; i++) {
    if (!labels[i] && labels[i] != -1) {
      labels[i] = ++act_label;
      // cout << i << '\n';
      dfs(i, act_label);
    }
  }

  return act_label == 1;
}

int main(void) {
  mainIO("closing");
  cin >> n >> m;
  g.resize(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bool ans = check_connected();
  int tmp;

  if (ans)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';

  for (int i = 0; i < n - 1; i++) {
    cin >> tmp;
    closed.push_back(tmp);
    ans = check_connected();
    if (ans)
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
  cin >> tmp;

  return 0;
}
