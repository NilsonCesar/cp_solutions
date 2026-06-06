#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {
    long long n, k, m, c, v;
    cin >> n >> k >> m;
    long long ans = 0;
    vector<long long> best(n + 7, -INF);
    multiset<long long, greater<long long>> gems;

    for (int i = 1; i <= n; i++) {
        cin >> c >> v;
        best[c] = max(v, best[c]);
        gems.insert(v);
    }

    sort(best.begin(), best.end());

    for (int i = n + 6; i >= n + 7 - m; i--) {
        ans += best[i];
        auto it = gems.find(best[i]);
        gems.erase(it);
        k--;
    }

    for (long long e : gems) {
        if (!k) break;
        ans += e;
        k--;
    }

    cout << ans << '\n';

    return 0;
}
