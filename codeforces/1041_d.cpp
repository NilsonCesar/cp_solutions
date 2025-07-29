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
    int n, h, i = 0, j = 0;
    long long ans = 0, temp_dist = 0;
    cin >> n >> h;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) cin >> x[i].first >> x[i].second;
    int d = x[0].first;

    while (j < n) {
        if (x[j].first - d < h) {
            temp_dist += x[j].first - d + x[j].second - x[j].first;
            h -= x[j].first - d;
            d = x[j].second;
            j++;
        } else if (i < j) {
            ans = max(temp_dist + h, ans);
            temp_dist -= x[i].second - x[i].first + x[i + 1].first - x[i].second;
            i++;
            h += x[i].first - x[i - 1].second;
        } else {
            i++; j++;
            temp_dist = 0;
            if (j < n) d = x[j].first;
        }
    }
    
    cout << max(ans, temp_dist + h) << '\n';

    return 0;
}
