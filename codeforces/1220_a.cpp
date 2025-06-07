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
    int n;
    cin >> n;
    map<char, int> l;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        l[c] += 1;
    }

    while (l['o'] && l['n'] && l['e']){
        l['o']--; l['n']--; l['e']--;
        cout << 1 << ' ';
    }
    while (l['z'] && l['e'] && l['r'] && l['o']) {
        l['z']--; l['e']--; l['r']--; l['o']--;
        cout << 0 << ' ';
    }
    cout << '\n';

    return 0;
}
