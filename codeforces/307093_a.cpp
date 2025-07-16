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
    unsigned long long n, m;
    cin >> n >> m;
    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unsigned long long ans = 0, ansI = 0, sum = a[0];

    long long i = 0, j = 0;
    while(j < n) {
        if (sum <= m) {
            j++;
            if (j < n) sum += a[j];
        } else {
            sum -= a[i];
            i++;
        }

        if (i > j) {
            j = i;
            sum = a[i];
        }

        // cout << sum << ' ' << i << ' ' << j << '\n';
        if (sum <= m) {
            ans = max(ans, sum);
            if (i != n and j != n) ansI = max(ansI, (unsigned long long) (j - i + 1));
        }
        // cout << sum << '\n';
        // cout << i << ' ' << j << '\n';
        if (i >= n or j >= n) break;
    }

    cout << ansI << '\n';

    return 0;
}
