#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int n, m, k, a;
    cin >> n >> m;
    vector<vector<int>> dishes(m);
    vector<int> b(n), dq(m), ans(n, 0);
    map<int, int> ing_to_day;

    for(int i = 0; i < m; i++) {
        cin >> k;
        dq[i] = k;
        dishes[i] = vector<int>(k);
        for(int j = 0; j < k; j++) {
            cin >> a;
            dishes[i][j] = a;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        ing_to_day[b[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        int max_day = 0;
        for(int j = 0; j < (int) dishes[i].size(); j++) {
            max_day = max(max_day, ing_to_day[dishes[i][j]]);
        }
        ans[max_day]++;
    }

    cout << ans[0] << '\n';
    for(int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
    }

    return 0;
}