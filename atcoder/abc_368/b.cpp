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

    int n, positives = 0, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            positives++;

    while(positives > 1) {
        positives = 0;
        sort(a.begin(), a.end());
        a[n - 1]--; a[n - 2]--;
        ans++;
        for(int i = 0; i < n; i++)
            if(a[i] > 0)
                positives++;
    }

    cout << ans << '\n';

    return 0;
}
