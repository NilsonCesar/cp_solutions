#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MAXG 2005

int cnt[MAXG][MAXG];
long long id_sum[MAXG][MAXG];
int only_by[2 * MAXN];

int main(void) {_
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;

        cnt[u][l]++;
        cnt[u][r + 1]--;
        cnt[d + 1][l]--;
        cnt[d + 1][r + 1]++;

        id_sum[u][l] += i;
        id_sum[u][r + 1] -= i;
        id_sum[d + 1][l] -= i;
        id_sum[d + 1][r + 1] += i;
    }

    int empty = 0;

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            id_sum[i][j] += id_sum[i - 1][j] + id_sum[i][j - 1] - id_sum[i - 1][j - 1];

            if (!cnt[i][j]) empty++;
            else if (cnt[i][j] == 1) {
                only_by[id_sum[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << empty + only_by[i] << '\n';

    return 0;
}
