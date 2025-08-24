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
    long long n, q, minSum = 0;
    int x, v;
    char c;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
        minSum += min(a[i], b[i]);

    while(q--) {
        cin >> c >> x >> v;
        x--;
        if (c == 'A') {
            if (a[x] <= b[x] && v <= b[x]) {
                minSum += v - a[x];
            } else if (a[x] <= b[x] && v > b[x]) {
                minSum += b[x] - a[x];
            } else if (a[x] > b[x] && v <= b[x]) {
                minSum -= b[x] - v;
            }

            a[x] = v;
        } else {
            if (b[x] <= a[x] && v <= a[x]) {
                minSum += v - b[x];
            } else if (b[x] <= a[x] && v > a[x]) {
                minSum += a[x] - b[x];
            } else if (b[x] > a[x] && v <= a[x]) {
                minSum -= a[x] - v;
            }

            b[x] = v;
        }
        cout << minSum << '\n';
    }

    return 0;
}
