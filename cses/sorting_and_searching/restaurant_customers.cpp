#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a;
    cin >> n;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        b.push_back({a, 1});
        cin >> a;
        b.push_back({a, -1});
    }
    sort(b.begin(), b.end());

    int cnt = 0, ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans = max(ans, cnt);
        cnt += b[i].second;
    }

    cout << ans << '\n';

    return 0;
}
