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
    int n, t, p, actP = 0, ans = 0, tmp;
    cin >> n >> t >> p;
    bool done[n];
    int l[n];
    
    for(int i = 0; i < n; i++) {
        done[i] = false;
        cin >> l[i];
        if(l[i] >= t) {
            actP++;
            done[i] = true;
        }
    }

    while(actP < p) {
        tmp = 0;
        for(int i = 0; i < n; i++) 
            if(l[i] < t)
                tmp = max(tmp, l[i]);
        ans += (t - tmp); 
        for(int i = 0; i < n; i++) { 
            l[i] += (t - tmp);
            if(l[i] >= t && !done[i]) {
                actP++;
                done[i] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
