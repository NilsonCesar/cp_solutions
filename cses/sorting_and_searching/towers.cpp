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
    cin >> n;
    vector<int> towers(n), ans;
    for(int i = 0; i < n; i++) cin >> towers[i];
    for(int i = 0; i < n; i++) {
        int j = upper_bound(ans.begin(), ans.end(), towers[i]) - ans.begin();
        if(j == (int) ans.size()) ans.push_back(towers[i]);
        else ans[j] = towers[i];
    }

    cout << (int) ans.size() << '\n';
    return 0;
}
