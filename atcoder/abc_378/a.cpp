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
    vector<int> a(4), visited(4, 0);
    int ans = 0;
    for(int i = 0; i < 4; i++)
	cin >> a[i];
    for(int i = 0; i < 4; i++)
	if(!visited[i]) {
	    visited[i] = 1;
	    for(int j = i + 1; j < 4; j++) {
		if(a[i] == a[j]) {
		    ans++;
		    visited[j] = 1;
		    break;
		}
	    }
	}
    cout << ans << '\n';
    return 0;
}
