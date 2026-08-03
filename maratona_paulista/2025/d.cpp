#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);

int n, m, p, s, a, b;
long long ans = 0;
map<int, map<int, bool>> deny;
vector<pair<int, int>> deny_v;
set<int> comb;

void check_comb(set<int>& comb) {
    for (pair<int, int> d : deny_v) {
        if (comb.count(d.first) && comb.count(d.second)) return;
    }
    ans++;
}

void check_all_ingredients(set<int>& comb, int i = p + s + 1) {
    if (i > n) check_comb(comb);
    else {
        check_all_ingredients(comb, i + 1);
        comb.insert(i);
        check_all_ingredients(comb, i + 1);
        comb.erase(i);
    }
}

void solve() {
    for (int i = 1; i <= p; i++) {
        comb.insert(i);
        for (int j = p + 1; j <= p + s; j++) {
            if (deny[i][j]) continue;
            comb.insert(j);
            check_all_ingredients(comb);
            comb.erase(j);
        }
        comb.erase(i);
    }
}

int main(void) {_
    cin >> n >> m >> p >> s;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        deny_v.push_back({min(a, b), max(a, b)});
        deny[min(a, b)][max(a, b)] = true;
    }

    solve();

    cout << ans << '\n';

    return 0;
}