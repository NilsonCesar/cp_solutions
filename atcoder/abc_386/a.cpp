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
    set<int> cards;
    for(int i = 0; i < 4; i++) {
    	int p;
	cin >> p;
	cards.insert(p);
    }
    if((int) cards.size() == 2) cout << "Yes";
    else cout << "No";
    cout << '\n';
    return 0;
}
