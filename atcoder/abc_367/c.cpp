#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

set<vector<int>> ans;

int n, k;
vector<int> r;

void solve(int act_n, vector<int> tmp_ans) {
    if(act_n == n) {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += tmp_ans[i];
        if(sum % k == 0) ans.insert(tmp_ans);
        return;
    }

    for(int i = 1; i <= r[act_n]; i++) {
        tmp_ans.push_back(i);
        solve(act_n + 1, tmp_ans);
        tmp_ans.pop_back();
    }
}

int main(void) {
    mainIO();

    cin >> n >> k;

    r.resize(n);

    for(int i = 0; i < n; i++) cin >> r[i];

    solve(0, vector<int>());

    for(vector<int> v : ans) {
        cout << v[0];
        for(int i = 1; i < n; i++) cout << ' ' << v[i];
        cout << '\n';
    }

    return 0;
}
