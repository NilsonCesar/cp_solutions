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

    int n, x, ans = 0;
    cin >> n >> x;
    vector<long long> sumpref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> sumpref[i];
        sumpref[i] += sumpref[i - 1];
    }
    
    int left = 0, right = 1;
    
    while(left <= n && right <= n) {
        while(right <= n) {
            if(sumpref[right] - sumpref[left] == x) {
                ans++;
                left++;
                break;
            } else if(sumpref[right] - sumpref[left] < x) {
                right++;
            } else {
                left++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
