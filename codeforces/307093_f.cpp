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
    int n, l = 0, r = 0;
    long long k, ans = 0;
    cin >> n >> k;
    vector<long long> a(n);
    priority_queue<pair<long long, int>> minN, maxN;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long minP = 0, maxP = 0;

    while(r < n) {
        if (a[maxP] - a[minP] <= k) {
            ans += r - l + 1;
            r++;
            if (r < n) {
                if (a[minP] >= a[r]) {
                    minP = r;
                }
                if (a[maxP] <= a[r]) {
                    maxP = r;
                }
                minN.push({-a[r], r});
                maxN.push({a[r], r});
            }
        } else {
            l++;
            minN.push({-a[l], l});
            maxN.push({a[l], l});
            if (minP < l) minP = l;
            if (maxP < l) maxP = l;

            while (minN.top().second < l) minN.pop();
            if (-minN.top().first <= a[minP]) {
                minP = minN.top().second;
                minN.pop();
            }

            while (maxN.top().second < l) maxN.pop();
            if (maxN.top().first >= a[maxP]) {
                maxP = maxN.top().second;
                maxN.pop();
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
