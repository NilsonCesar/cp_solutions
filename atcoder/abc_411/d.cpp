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
    int n, q, op, p;
    string s;
    cin >> n >> q;
    string server;
    vector<string> pcs(n + 1);
    while (q--) {
        cin >> op >> p;
        if (op == 1) {
            pcs[p] = server;
        } else if (op == 2) {
            cin >> s;
            pcs[p].append(s);
        } else {
            server = pcs[p];
        }
    }

    cout << server << '\n';

    return 0;
}
