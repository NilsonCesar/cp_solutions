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
    mainIO("pairup");
    int n, x, y, qtd;
    long long ans = 0;
    cin >> n;
    vector<vector<long long>> cows(n);
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cows[i] = {y, x};
    }
    sort(cows.begin(), cows.end());

    int i = 0, j = n - 1;
    
    while(i < j) {
        ans = max(ans, cows[i][0] + cows[j][0]);
        qtd = min(cows[i][1], cows[j][1]);
        cows[i][1] -= qtd;
        cows[j][1] -= qtd;
        
        if(cows[i][1] == 0) i++;
        if(cows[j][1] == 0) j--;
    }
    
    cout << ans << '\n';

    return 0;
}