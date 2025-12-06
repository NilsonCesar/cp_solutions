#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, q, l, r;
    cin >> n >> q;
    long long black = 0;
    set<pair<long long, long long>> inter;

    while(q--) {
        cin >> l >> r;
        auto it = inter.lower_bound({l, 0});

        if (it != inter.begin()) {
            it--;
            if (it->second < l) it++; 
        }

        while(it != inter.end() && it->first <= r) {
            l = min(l, it->first);
            r = max(r, it->second);
            black -= (it->second - it->first + 1);
            it = inter.erase(it);
        }

        black += (r - l + 1);
        inter.insert({l, r});

        cout << n - black << '\n';
    }

    return 0;
}
