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
    int n, k, l, r;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> k;
    while (k--) {
        cin >> l >> r;
        l = lower_bound(a.begin(), a.end(), l) - a.begin();
        r = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << r - l << ' '; 
    }
    cout << '\n';

    return 0;
}
