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
    int sum = 0, x;
    cin >> x;
    for(int i = 1; i <= 9; i++)
	for(int j = 1; j <= 9; j++)
	    if(i * j != x)
	      sum += i * j;
    cout << sum << '\n';
    return 0;
}

