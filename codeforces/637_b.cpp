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
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];
    set<string> already;

    for (int i = n - 1; i >= 0; i--) {
        if (!already.count(names[i])) {
            cout << names[i] << '\n';
            already.insert(names[i]);
        }
    }

    return 0;
}