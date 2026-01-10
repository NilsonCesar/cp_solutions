#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 30

int main(void) {_
    int n, q, t, b;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> up(n + 1, vector<int>(MAXN));
    vector<vector<long long>> sum(n + 1, vector<long long>(MAXN));

    for (int i = 1; i <= n; i++) {
        up[i][0] = a[i];
        sum[i][0] = i;
    }

    for (int j = 1; j < MAXN; j++) {
        for (int i = 1; i <= n; i++) {
            int m = up[i][j - 1];
            up[i][j] = up[m][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[m][j - 1];
        }
    }

    while(q--) {
        cin >> t >> b;

        long long ans = 0;
        int cur_person = b;

        for (int j = MAXN - 1; j >= 0; j--) {
            if ((t >> j) & 1) {
                ans += sum[cur_person][j];
                cur_person = up[cur_person][j];
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
