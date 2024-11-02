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
    mainIO("lemonade");
    int n, ans = 0;
    cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n; i++) cin >> cows[i];
    sort(cows.begin(), cows.end());
    int j = n - 1;
    while(j >= 0 && cows[j] >= n - j - 1) {
	    ans++;
	    j--;
    }
    cout << ans << '\n';
    return 0;
}
