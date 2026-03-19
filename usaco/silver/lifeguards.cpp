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
    mainIO("lifeguards");
    long long n, l, r, sum = 0, rr = -1;
    cin >> n;
    set<long long> opens;
    vector<vector<long long>> t, tt;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        t.push_back({l, i});
        t.push_back({r, i});
        tt.push_back({l, r});
    }

    
    sort(t.begin(), t.end());
    sort(tt.begin(), tt.end());
    tt.push_back({1000000000+7, 1000000000+7});
    l = tt[0][0], r = tt[0][1];
    for (int i = 1; i < n + 1; i++) {
        if (tt[i][0] <= r) r = max(r, tt[i][1]);
        else {
            sum += r - l;
            l = tt[i][0];
            r = tt[i][1];
        }
    }
    
    int ans = 2e9;
    vector<int> alone(n, 0);
    r = t[0][0];
    for (int i = 0; i < 2 * n; i++) {
        if (opens.size() == 1) {
            int id = *opens.begin();
            alone[id] += t[i][0] - r;
        }

        if (opens.find(t[i][1]) != opens.end()) {
            opens.erase(t[i][1]);
        } else {
            opens.insert(t[i][1]);
        }

        r = t[i][0];
    }

    for (int i = 0; i < n; i++) {
        ans = min(ans, alone[i]);
    }

    cout << sum - ans << '\n';
    
    return 0;
}
