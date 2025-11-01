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
    int n, a, b, ans = 0;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    vector<int> sum_a(n + 1, 0), sum_b(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        sum_a[i] = sum_a[i - 1] + (s[i - 1] == 'a');
        sum_b[i] = sum_b[i - 1] + (s[i - 1] == 'b');
    }

    for (int i = 1; i <= n; i++) {
        int idx_a = lower_bound(sum_a.begin() + i, sum_a.end(), sum_a[i] + a - (s[i - 1] == 'a')) - sum_a.begin();
        int idx_b = lower_bound(sum_b.begin() + i, sum_b.end(), sum_b[i] + b - 1) - sum_b.begin();
        if (idx_a == n + 1 || idx_b == n + 1) continue;
        cout << idx_a << ' ' << idx_b << sum_a[idx_a] - sum_a[i] << ' ' << sum_b[idx_b] - sum_b[i] << '\n';
    }

    cout << ans << '\n';
    
    return 0;
}
