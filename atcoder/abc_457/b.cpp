#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, l, i, j;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; j++) cin >> a[i][j];
    }

    cin >> i >> j;
    cout << a[i - 1][j - 1] << '\n';

    return 0;
}
