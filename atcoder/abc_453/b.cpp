#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t, x, a;
    cin >> t >> x;
    vector<pair<int, int>> s;
    cin >> a;
    s.push_back({0, a});
    for (int i = 1; i <= t; i++) {
        cin >> a;
        if (abs(s.back().second - a) >= x) {
            s.push_back({i, a});
        }
    }

    for (pair<int, int> p : s) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
