#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, d;
    cin >> n >> d;
    vector<vector<int>> products(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
        cin >> products[i][0] >> products[i][1];
    sort(products.begin(), products.end());
    int r = 0;
    long long tv = products[0][1];
    vector<long long> best(n);
    best[0] = products[0][1];
    long long resp = 0;
    for (int l = 0; l < n; l++) {
        // cout << l << ' ' << r << '\n';
        // cout << v1 << ' ' << v2 << '\n';
        while(r + 1 < n && products[r + 1][0] - products[l][0] <= d) {
            tv += products[++r][1];
            best[r] = max(best[r - 1], tv);
        }
        resp = max(resp, tv + (l > 0 ? best[l - 1] : 0));
        tv -= products[l][1];
    }

    cout << resp << '\n';

    return 0;
}
