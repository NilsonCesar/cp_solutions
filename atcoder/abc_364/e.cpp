#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int x, y;

bool my_compare(pair<int, int> a, pair<int, int> b) {
    int sum_a = a.first + a.second;
    int sum_b = b.first + b.second;

    

    return sum_a < sum_b;
}

int main(void) {
    mainIO();
    int n, ans = 0;
    long long countSw = 0, countSl = 0;
    cin >> n >> x >> y;
    vector<pair<long long, long long>> dishes(n);

    for(int i = 0; i < n; i++) cin >> dishes[i].first >> dishes[i].second;

    sort(dishes.begin(), dishes.end(), my_compare);

    for(int i = 0; i < n && countSw <= x && countSl <= y; i++) {
        countSw += dishes[i].first;
        countSl += dishes[i].second;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
