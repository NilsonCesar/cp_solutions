#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i].second >> m[i].first;
    sort(m.begin(), m.end());

    int ans = 0;

    while(k-- && m.size() != 0) {
        vector<pair<int, int>> tmp;
        int r = m[0].first;
        int tmp_ans = 1;
        for (int i = 1; i < (int) m.size(); i++) {
            if (r <= m[i].second) {
                tmp_ans++;
                r = m[i].first;
            } else {
                tmp.push_back(m[i]);
            }
        }
        m = tmp;
        ans += tmp_ans;
    }

    cout << ans << '\n';

    return 0;
}
