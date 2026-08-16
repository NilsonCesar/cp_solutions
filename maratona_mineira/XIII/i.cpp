#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dip_langs(n + 1);
    vector<vector<int>> dist(m + 1, vector<int>(m + 1, INF));

    for (int i = 0; i <= m; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        dip_langs[i].resize(k);

        for (int j = 0; j < k; j++) {
            cin >> dip_langs[i][j];
        }

        for (int j = 0; j < k; j++) {
            for (int w = j + 1; w < k; w++) {
                int l1 = dip_langs[i][j];
                int l2 = dip_langs[i][w];
                dist[l1][l2] = 1;
                dist[l2][l1] = 1;
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    vector<vector<int>> dip_to_langs(n + 1, vector<int>(m + 1, INF));

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            for (int j = 0; j < (int) dip_langs[i].size(); j++) {
                dip_to_langs[i][l] = min(dip_to_langs[i][l], dist[dip_langs[i][j]][l]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int ans = INF;

        for (int j = 0; j < (int) dip_langs[b].size(); j++) {
            ans = min(ans, dip_to_langs[a][dip_langs[b][j]]);
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}
