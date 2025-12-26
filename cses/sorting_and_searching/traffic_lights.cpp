#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int x, n, p;
    cin >> x >> n;
    set<pair<int, int>> s;
    multiset<int> l;
    s.insert({x, 0});
    l.insert(x);
    while(n--) {
        cin >> p;
        auto it = s.lower_bound({p, p});
        int left = it->second, right = it->first;
        s.erase(it);
        l.erase(l.find(right - left));
        s.insert({p, left});
        s.insert({right, p});
        l.insert(p - left);
        l.insert(right - p);
        cout << *l.rbegin() << '\n';
    }

    return 0;
}
