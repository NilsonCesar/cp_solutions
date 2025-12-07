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
    long long acc = 0, ans = 0, a;
    cin >> n;
    vector<long long> sumpref(n, 0);
    sumpref[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        acc += a;

        ans += sumpref[(acc % n + n) % n];
        sumpref[(acc % n + n) % n]++;
    }
 
    // ans = 0;
    // for(int i = 0; i < n; i++)
    //     ans += sumpref[i] * (sumpref[i] - 1) / 2;
 
    cout << ans << '\n';
 
    return 0;
}