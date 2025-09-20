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
    int n, m, k, a, b;
    cin >> n >> m >> k;
    int total_sum = m * (m + 1) / 2;
    map<int, int> solve;
    vector<int> all;

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        solve[a] += b;
        if (solve[a] == total_sum) {
            all.push_back(a);
        }
    }

    for (int i = 0; i < (int) all.size(); i++)
        cout << all[i] << ' ';
    if ((int) all.size())
        cout << '\n';

    return 0;
}
