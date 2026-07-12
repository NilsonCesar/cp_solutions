#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, r, c;
    cin >> n >> m;

    vector<int> rows(n + 1, 0), columns(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        columns[rows[r]] = 0;
        rows[columns[c]] = 0;
        rows[r] = c;
        columns[c] = r;
    }

    set<pair<int, int>> ans;

    for (int r = 1; r <= n; r++) {
        if (rows[r]) ans.insert({r, rows[r]});
        if (columns[r]) ans.insert({columns[r], r});
    }

    cout << (int) ans.size() << '\n';

    return 0;
}
