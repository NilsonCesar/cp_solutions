#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k;
    ordered_set s;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) s.insert(i);

    int pos = 0;
    while (!s.empty()) {
        pos = (pos + k) % (s.size());
        auto it = s.find_by_order(pos);
        cout << *it << ' ';
        s.erase(it);
    }
    cout << '\n';

    return 0;
}
