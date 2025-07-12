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
    unsigned long long count = 0;
    cin >> n;
    vector<pair<char, unsigned long long>> ci(n);
    for (int i = 0; i < n; i++) {
        cin >> ci[i].first >> ci[i].second;
        if (count > 100) continue;
        count += ci[i].second;
    }

    if (count <= 100) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ci[i].second; j++) cout << ci[i].first;
        }
    } else {
        cout << "Too Long";
    }
    cout << '\n';

    return 0;
}
