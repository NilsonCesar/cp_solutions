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
    pair<int, int> t, f = {0, 0};
    int n;
    string s;
    cin >> n >> t.first >> t.second >> s;
    set<pair<int, int>> hist;
    hist.insert(f);

    for(int i = 0; i < (int) s.size(); i++) {
      if(s[i] == 'N') {
        t.first++;
	f.first++;
      }
      if(s[i] == 'W') {
	t.second++;
	f.second++;
      }
      if(s[i] == 'S') {
	t.first--;
	f.first--;
      }
      if(s[i] == 'E') {
	t.second--;
	f.second--;
      }
      hist.insert(f);
      if(hist.find(t) == hist.end()) cout << '0';
      else cout << '1';
    }
    cout << '\n';

    return 0;
}
