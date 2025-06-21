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
    int n, q, b = 0, s;
    cin >> n >> q;
    vector<bool> a(n + 2, false);

    while (q--) {
        cin >> s;
        if (a[s]) {
            if (a[s - 1] && a[s + 1]) b++;
            else if (!a[s - 1] && !a[s + 1]) b--;
        } else {
            if (a[s - 1] && a[s + 1]) b--;
            else if (!a[s - 1] && !a[s + 1]) b++;
        }
        a[s] = !a[s];
        cout << b << '\n';
    }

    return 0;
}
