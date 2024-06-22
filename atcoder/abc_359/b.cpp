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
    int n, ans = 0;
    cin >> n;
    n *= 2;
    vector<int> clothes(n);
    for(int i = 0; i < n; i++) cin >> clothes[i];
    for(int i = 0; i < n - 2; i++) ans += (clothes[i] == clothes[i + 2]);
    cout << ans << '\n';
    return 0;
}
