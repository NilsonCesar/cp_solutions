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
    int k, ak = 0, ans = 0;
    cin >> k;
    vector<int> months(12);
    for (int i = 0; i < 12; i++) cin >> months[i];
    sort(months.begin(), months.end(), greater<>());
    while (k > ak && ans < 12) ak += months[ans++];

    cout << (ak >= k ? ans : -1) << '\n';

    return 0;
}
