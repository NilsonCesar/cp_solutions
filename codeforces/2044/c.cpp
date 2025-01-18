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
	int m, a, b, c, ans = 0;
	cin >> m >> a >> b >> c;
	ans += min(a, m);
	if(min(a, m) == a) {
	    ans += min(c, m - a);
	    c -= min(c, m - a);
	}
	ans += min(b, m);
	if(min(b, m) == b) {
	    ans += min(c, m - b);
	    c -= min(c, m -b);
	}
	cout << ans << '\n';
    }

    return 0;
}
