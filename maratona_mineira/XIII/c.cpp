#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(void) {_
    int n, c, p = 0;
    cin >> n;
    set<int, greater<int>> cnt;
    vector<pair<int, int>> q;
    map<int, int> idx;

    for (int i = 1; i <= n; i++) {
        cin >> c;
        while(cnt.find(c) != cnt.end()) {
            cnt.erase(q[p++].first);
        }
        cnt.insert(c);
        idx[c] = i;
        q.push_back({c, i});
        cout << *cnt.begin() << ' ' << idx[*cnt.begin()] << '\n';
    }

    return 0;
}