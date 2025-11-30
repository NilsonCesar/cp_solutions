#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 5007

int edit_distance[MAXN][MAXN];

int main(void) {_
    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();

    for (int i = 0; i <= m; i++)
        edit_distance[n][i] = m - i;
    for (int i = 0; i <= n; i++)
        edit_distance[i][m] = n - i; 


    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) edit_distance[i][j] = edit_distance[i + 1][j + 1];
            else {
                edit_distance[i][j] = edit_distance[i + 1][j + 1];
                edit_distance[i][j] = min(edit_distance[i][j + 1], edit_distance[i][j]);
                edit_distance[i][j] = min(edit_distance[i + 1][j], edit_distance[i][j]);
                edit_distance[i][j]++;
            }
        }
    }

    cout << edit_distance[0][0] << '\n';

    return 0;
}
