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
    mainIO("");
    int n, m, f;
    cin >> n >> m;
    vector<int> a(m), x(m, 0);

    for(int i = 0; i < m; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> f;
            x[j] += f;
        }

    for(int i = 0; i < m; i++)
        if(a[i] > x[i]) {
            cout << "No" << '\n';
            return 0;
        }

    cout << "Yes" << '\n';

    return 0;
}
