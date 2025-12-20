#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long maxp = 0, p, w, maxCost = 0;
        vector<long long> cost;
        for (int i = 0; i < n; i++) {
            cin >> w >> p;
            maxp += p;
            cost.push_back(w + p);
        }
        sort(cost.begin(), cost.end());
        int ans = 0, i = 0;
        // cout << maxp << '\n';
        while (i < n && maxp >= maxCost + cost[i]) {
            maxCost += cost[i];
            ans++;
            i++;
        }
        cout << ans << '\n';
    }

    return 0;
}
