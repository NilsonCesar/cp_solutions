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
    map<int, long long> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    long long ans = 0;
    map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (visited[a[i]]) continue;
        if (f[a[i]] < 2) continue;
        visited[a[i]] = true;
        long long pos = f[a[i]] * (f[a[i]] - 1) / 2;
        ans += 1LL * ((int) a.size() - f[a[i]]) * pos;
    }

    cout << ans << '\n';

    return 0;
}
