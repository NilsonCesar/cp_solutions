#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, m, u, v;
    cin >> n >> m;
    vector<vector<long long>> g(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        long long q = n - ((long long) g[i].size()) - 1;
        if (q <= 2) cout << 0;
        else cout << (q) * (q - 1) * (q - 2) / 6;
        cout << ' ';
    }
    cout << '\n';

    return 0;
}
