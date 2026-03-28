#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int q, op, h;
    cin >> q;
    multiset<int> t;
    while (q--) {
        cin >> op >> h;
        if (op == 1) {
            t.insert(h);
        } else {
            int p;
            while (!t.empty()) {
                p = *t.begin();
                if (p > h) break;
                t.erase(p);
            }
        }
        cout << t.size() << '\n';
    }

    return 0;
}
