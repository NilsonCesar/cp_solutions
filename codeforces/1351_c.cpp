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
    int t;
    cin >> t;
    while(t--) {
        set<pair<pair<int, int>, pair<int, int>>> m;
        string path;
        int ans = 0;
        pair<int, int> a = {0, 0};
        cin >> path;
        for (char c : path) {
            pair<int, int> b = a;
            if (c == 'N') b.first++;
            else if (c == 'S') b.first--;
            else if (c == 'W') b.second--;
            else b.second++;
            if (m.count({a, b}) || m.count({b, a})) ans++;
            else ans += 5;
            m.insert({a, b});
            a = b;
        }
        cout << ans << '\n';
    }

    return 0;
}
