#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

double pi = acos(-1);

vector<pair<double, int>> v;

int main(void) {_
    int t, n, x, h;
    double len;
    cin >> t >> n;

    cout << setprecision(15);
    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        len = h / tan(t * pi / 180);
        v.push_back({x, 1});
        v.push_back({x + len, -1});
    }   
    sort(v.begin(), v.end());

    double ans = 0;
    int cnt = 0;

    for (int i = 0; i < (int) v.size(); i++) {
        if (cnt > 0) {
            ans += v[i].first - v[i - 1].first;
        }
        cnt += v[i].second;
    }

    cout << ans << '\n';

    return 0;
}
