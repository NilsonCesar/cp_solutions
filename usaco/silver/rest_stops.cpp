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
    mainIO("");
    long long l, n, rf, rb, pf = 0, i = 0;
    long long ans = 0;
    cin >> l >> n >> rf >> rb;
    vector<vector<long long>> stops(n, vector<long long>(2));
    for(int i = 0; i < n; i++) cin >> stops[i][0] >> stops[i][1];

    while(i < n) {
	long long max_taste = (stops[i][0] - pf) * (rf - rb) * stops[i][1], max_i = i;
	for(int ii = i + 1; ii < n; ii++) {
	    long long tmp = (stops[ii][0] - pf) * (rf - rb) * stops[ii][1];
	    if(max_taste <= tmp) {
	        max_taste = tmp;
		max_i = ii;
	    }
	}
	ans += max_taste;
	pf = stops[max_i][0];
	i = max_i + 1;
    }

    cout << ans << '\n';
    return 0;
}
