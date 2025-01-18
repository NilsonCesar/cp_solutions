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
	int n, ans = 0;
	cin >> n;
	for(int a = 1; a < n; a++)
	    for(int b = 1; b < n; b++)
		if(a + b == n)
		    ans++;
	cout << ans << '\n';
    }
    return 0;
}
