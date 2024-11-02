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
    int n, pos = 0;
    cin >> n;
    vector<int> a(n), b(n), prev(n);
    map<int, int> conv;
    for(int i = 0; i < n; i++) {
	cin >> a[i];
	if(conv.count(a[i]) > 0) {
	    b[i] = prev[conv[a[i]]];
	    prev[conv[a[i]]] = i + 1;
	} else {
	    b[i] = -1;
	    conv[a[i]] = pos++;
	    prev[conv[a[i]]] = i + 1;
	}
    }
    for(int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << '\n';
    return 0;
}
