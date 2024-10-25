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
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for(int i = 0; i < n; i++) cin >> applicants[i];
    for(int i = 0; i < m; i++) cin >> apartments[i];
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0) {
        while(j >= 0 && (apartments[j] - applicants[i]) > k) j--;
        if(j < 0) break;
        if(abs(applicants[i] - apartments[j]) <= k) {
            ans++;
            i--;
            j--;
        } else i--;
    }
    
    cout << ans << '\n';
    return 0;
}
