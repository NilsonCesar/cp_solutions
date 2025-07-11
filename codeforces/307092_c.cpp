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
    int n, m;
    unsigned long long ans = 0;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    map<int, long long> freq;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        freq[b[i]]++;
    }

    int j = 0, count;
    for (int i = 0; i < m;) {
        count = 0;
        while (j < n && a[j] <= b[i]) {
            if (a[j] == b[i]) count++;
            j++;
        }
        ans += count * freq[b[i]];
        i += freq[b[i]];
    }

    cout << ans << '\n';

    return 0;
}
