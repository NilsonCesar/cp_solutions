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
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int i = 0, j = n - 1;
    while(i <= j) {
        ans++;
        if(i == j) break;
        else if(w[i] + w[j] <= x) {
            i++;
            j--;
        } else j--;
    } 
    
    cout << ans << '\n';
    return 0;
}
