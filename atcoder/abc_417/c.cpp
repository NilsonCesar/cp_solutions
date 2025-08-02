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
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (freq.find(i - a[i]) != freq.end()) ans += freq[i - a[i]];
        freq[i + a[i]]++;
    }

    cout << ans << '\n';

    return 0;
}
