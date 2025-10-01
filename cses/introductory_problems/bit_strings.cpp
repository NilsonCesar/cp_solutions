#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define MOD 1000000007

int main(void) {
    mainIO();
    int n;
    cin >> n;
    long long ans = 1;

    for (int i = 0; i < n; i++)
        ans = (ans * 2) % MOD;
    
    cout << ans << '\n';

    return 0;
}
