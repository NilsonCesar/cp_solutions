#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, lastNumber = 0, length = 0, j;
vector<int> a;
map<int, int> dp;

int main(void) {
    mainIO();
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int num = a[i];
        dp[num] = dp[num - 1] + 1;

        if (length < dp[num]) {
            length = dp[num];
            lastNumber = num;
        }
    }

    cout << length << '\n';
    for (int i = 0; i < n; i++) {
        if (lastNumber - length + 1 == a[i]) {
            cout << i + 1 << ' ';
            length--;
        }
    }
    cout << '\n';

    return 0;
}
