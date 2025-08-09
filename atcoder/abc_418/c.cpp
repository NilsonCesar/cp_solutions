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
    int n, q, b;
    cin >> n >> q;
    vector<int> bags(n);
    vector<long long> sum(n);
    for (int i = 0; i < n; i++)
        cin >> bags[i];
    sort(bags.begin(), bags.end());
    sum[0] = bags[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + bags[i];

    for (int i = 0; i < q; i++) {
        cin >> b;
        int idx = lower_bound(bags.begin(), bags.end(), b) - bags.begin(); 
        if (idx < n) {
            if (idx == 0) cout << b + (b - 1) * (n - 1);
            else cout << sum[idx - 1] + bags[idx - 1] * (n - idx) + (b - bags[idx - 1]);
        } else {
            cout << -1;
        }
        cout << '\n';
    }

    return 0;
}
