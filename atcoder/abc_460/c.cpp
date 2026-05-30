#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    multiset<int> shari, neta;
    int n, m, s, ne;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        shari.insert(s);
    }

    for (int i = 0; i < m; i++) {
        cin >> ne;
        neta.insert(ne);
    }

    int ans = 0;
    for (int sha : shari) {
        auto it = neta.lower_bound(0);

        if (it != neta.end() && *it <= 2 * sha) {
            ans++;
            neta.erase(it);
        }
    }

    cout << ans << '\n';

    return 0;
}
