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

    int n, j;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0, qtd;
    for (int i = 0; i < n; i++) {
        j = i;
        while(j < n && a[j] == a[i]) j++;
        qtd = j - i;
        ans += qtd * (qtd + 1) / 2; 
        i = j - 1;
    }

    cout << ans << '\n';

    return 0;
}
