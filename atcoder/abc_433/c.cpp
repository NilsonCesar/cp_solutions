#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string s;
    cin >> s;
    vector<pair<int, int>> v;
    pair<int, int> p;
    int i = 0, n = (int) s.size(), d, ans = 0;
    while(i < n) {
        d = s[i] - '0';
        p = {d, 0};
        while (i < n && (s[i] - '0') == d) {p.second++; i++;}
        v.push_back(p);
    }

    i = 0;
    while(i < -1 + (int) v.size()) {
        if(v[i].first == v[i + 1].first - 1) 
            ans += min(v[i].second, v[i + 1].second);
        i++;
    }
    cout << ans << '\n';

    return 0;
}
