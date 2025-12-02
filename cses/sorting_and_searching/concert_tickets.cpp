#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, t;
    cin >> n >> m;
    multiset<int> s;

    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        auto v = s.upper_bound(t);
        if (v == s.begin()) {
            cout << -1 << '\n';
        } else {
            v--;
            cout << *v << '\n';
            s.erase(v);
        }
    }


    return 0;
}
