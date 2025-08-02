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
    int n, m, b;
    cin >> n >> m;
    multiset<int> a; 
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.insert(b);
    }

    for (int i = 0; i < m; i++) {
        cin >> b;
        if (a.count(b)) {
            int c = a.count(b) - 1;
            a.erase(b);
            for (int j = 0; j < c; j++) a.insert(b);
        }
    }

    for (int e : a) 
        cout << e << ' ';
    cout << '\n';

    return 0;
}
