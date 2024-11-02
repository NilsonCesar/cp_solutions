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
    int N, Q, t, d;
    cin >> N;
    vector<int> q(N), r(N);
    for(int i = 0; i < N; i++)
	cin >> q[i] >> r[i];
    cin >> Q;
    while(Q--) {
    	cin >> t >> d;
	int mod = d % q[t - 1];
	if(mod == r[t - 1]) cout << d;
	else if(mod < r[t - 1]) cout << r[t - 1] - mod + d;
	else cout << q[t - 1] - mod + r[t - 1] + d;
	cout << '\n';
    }
    return 0;
}
