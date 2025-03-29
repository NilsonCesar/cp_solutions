#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;
       vector<int> a(2 * n);
       for (int i = 0; i < 2 * n; i++) cin >> a[i];
       vector<vector<int>> positions(n + 1);
       set<pair<int, int>> ans;
       for(int i = 0; i < 2 * n; i++) positions[a[i]].push_back(i);
       for(int i = 0; i < 2 * n - 1; i++) {
	  int x = a[i], y = a[i + 1];
	  if (x == y) continue;
	  if (abs(positions[x][0] - positions[x][1]) == 1) continue;
	  if (abs(positions[y][0] - positions[y][1]) == 1) continue;
	  vector<int> v = {positions[x][0], positions[x][1], positions[y][0], positions[y][1]};
	  sort(v.begin(), v.end());
	  if(v[0] + 1 == v[1] and v[2] + 1 == v[3]) ans.emplace(minmax(x, y));
       }
       cout << ans.size() << '\n';
    }
    return 0;
}
