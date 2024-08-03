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
    int n, sw = 0, sl = 0;
    long long x, y, count_sw = 0, count_sl = 0;
    cin >> n >> x >> y;
    vector<pair<long, long>> first_sweet(n), first_salt(n); 

    for(int i = 0; i < n; i++) {
        cin >> first_sweet[i].first;
        first_salt[i].second = first_sweet[i].first;
    }

    for(int i = 0; i < n; i++) {
        cin >> first_salt[i].first;
        first_sweet[i].second = first_salt[i].first;
    }

    sort(first_sweet.begin(), first_sweet.end());
    sort(first_salt.begin(), first_salt.end());
    reverse(first_sweet.begin(), first_sweet.end());
    reverse(first_salt.begin(), first_salt.end());

    while(sw < n && count_sw <= x) count_sw += first_sweet[sw++].first;
    while(sl < n && count_sl <= y) count_sl += first_salt[sl++].first;

    cout << min(sw, sl) << '\n';

    return 0;
}
