#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 1000000000000000
#define MAXN 507

int n, m;
long long g[MAXN][MAXN];

int main(void) {_
    long long a, b, c, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++)
        g[i][i] = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }


    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                if (g[i][k] != INF && g[k][j] != INF)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    while (q--) {
        cin >> a >> b;
        cout << (g[a][b] == INF ? -1 : g[a][b]) << '\n';
    }
    
    return 0;
}
