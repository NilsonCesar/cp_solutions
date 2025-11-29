#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 1007

int memo[MAXN][MAXN];

int main(void) {_
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    vector<int> ans;
    int act_memo = 0;

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            memo[i][j] = (a[i] == b[j]) + memo[i + 1][j + 1];
            memo[i][j] = max(memo[i][j], memo[i + 1][j]);
            memo[i][j] = max(memo[i][j], memo[i][j + 1]);
            // cout << memo[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << memo[1][1] << '\n';

    int i = 1, j = 1;

    while(i <= n && j <= m) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++; j++;
        } else {
            if (memo[i + 1][j] >= memo[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }
    }

    for (int i = 0; i < memo[1][1]; i++) cout << ans[i] << ' ';
    cout << '\n';


    return 0;
}
