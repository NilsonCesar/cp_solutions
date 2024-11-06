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
    int n, m, max_b = -1, min_g = 2e9;
    unsigned long long ans = 0;
    cin >> n >> m;
    int b[n], g[m];

    for(int i = 0; i < n; i++) {
	cin >> b[i];
	max_b = max(max_b, b[i]);
    }

    for(int i = 0; i < m; i++) {
	cin >> g[i];
	min_g = min(min_g, g[i]);
	ans += g[i];
    }

    if(min_g < max_b) {
	cout << -1 << '\n';
	return 0;
    }

    sort(b, b + n);

    bool in_sum = false;
    for(int i = 0; i < m; i++)
	if(b[n - 1] == g[i])
	    in_sum = true;

    if(!in_sum) ans += ((unsigned long long) b[n - 1]) + ((unsigned long long) (m - 1)) * ((unsigned long long) b[n - 2]);


    for(int i = 0; i < n - 1 - !in_sum; i++) ans += ((unsigned long long) m) * ((unsigned long long) b[i]);

    cout << ans << '\n';

    return 0;
}
