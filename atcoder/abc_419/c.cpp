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
    int n;
    long long x = 0, y = 0;
    cin >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        x += p[i].first;
        y += p[i].second;
    }

    long long i = 0, j = 2e9, mid, ans;
    
    while (i <= j) {
        mid = (i + j) / 2;
        long long rMin = -(1e9 + 7), rMax = 1e9 + 7, cMin = -(1e9 + 7), cMax = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            rMin = max(rMin, p[i].first - mid);
            rMax = min(rMax, p[i].first + mid);
            cMin = max(cMin, p[i].second - mid);
            cMax = min(cMax, p[i].second + mid);
        }
        if (rMax >= rMin && cMax >= cMin) {
            ans = mid;
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
