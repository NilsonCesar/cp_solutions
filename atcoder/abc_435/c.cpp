#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a, ans = 1, falls = 1;
    cin >> n;
    vector<pair<int,int>> x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        x.push_back({i, 1});
        x.push_back({i + a, -1});
    }
    sort(x.begin(), x.end());
    for (int i = 1; i < (int) x.size(); i++) {
        if (x[i].second == 1) {
            ans++;
        }
        falls += x[i].second;
        if (!falls) break;
    }

    cout << ans << '\n';
    return 0;
}
