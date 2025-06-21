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
    vector<int> d(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1]; 
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) cout << d[j] - d[i] << ' ';
        cout << '\n';
    }

    return 0;
}
