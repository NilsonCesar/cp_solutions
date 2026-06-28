#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void solve() {
    int n, h, w;
    cin >> n;

    vector<int> r(n, -1);
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        
        cin >> h >> w;
        v.push_back({h, -w, i});
        v.push_back({w, -h, i});
    }

    sort(v.begin(), v.end());

    int a = v[0][1];
    int b = v[0][2];

    for (int i = 1; i < 2 * n; i++) {
        if (v[i][1] < a) {
            r[v[i][2]] = b + 1;
        } else {
            a = v[i][1];
            b = v[i][2];
        }
    }

    for (int i = 0; i < n; i++) cout << r[i] << ' ';
    cout << '\n';
}


int main(void) {_
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
