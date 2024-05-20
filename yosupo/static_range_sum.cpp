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
    mainIO("");
    int n, q, l, r;
    cin >> n >> q;
    vector<unsigned long long> sumpref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> sumpref[i];
        sumpref[i] += sumpref[i - 1];
    }

    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << sumpref[r] - sumpref[l] << '\n';
    }

    return 0;
}
