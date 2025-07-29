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
    int n, m, i, j, k = 0, b = -1;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    if (a[0].first != 1) {
        cout << "NO" << '\n';
        return 0;
    }

    j = 1;

    while(k < n) {
        if (j > m) break;
        if (a[k].first <= j && j <= a[k].second) {
            if (~b) b = k;
            else if (a[b].second < a[k].second) b = k;
        } else if (a[k].second > j) {
            j = a[b].second + 1;
            ans.push_back(b);
            b = -1;
            continue;
        }
        k++;
    } 
    if (a[b].first <= j && j <= a[b].second) {
        j = a[b].second + 1;
        ans.push_back(b);
    }

    if (j > m) {
        cout << "YES" << '\n';
        cout << (int) ans.size() << '\n';
        for (int i = 0; i < (int) ans.size(); i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
