#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int s, p, u, v, t = 1;

    while((cin >> p >> s) && (s != 0 || p != 0)) {
        cout << "Teste " << t++ << '\n';
        vector<int> b(p + 1, 0);
        int prev = INF;
        for (int i = 0; i < s; i++) {
            cin >> u >> v;
            b[u]++;
            b[v]--;
            prev = min(prev, b[u]);
        }

        int cnt = 0;
        for (int i = 0; i < p + 1; i++) {
            if (b[i] > 0 && cnt == 0) {
                prev = i;
            }
            cnt += b[i];
            if (b[i] < 0 && cnt == 0) {
                cout << prev << ' ' << i << '\n';
            }
        }
    }

    return 0;
}
