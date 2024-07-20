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
    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        long long ans = 0;
        cin >> n;
        vector<long long> sumpref(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> c;
            sumpref[i] = sumpref[i - 1] + (c - '0');
        }

        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                ans += ((sumpref[j] - sumpref[i - 1]) == (j - i + 1));
    
        cout << ans << '\n';
    }

    return 0;
}