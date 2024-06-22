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
    mainIO("maxcross");
    int n, k, b, ans, idx;
    cin >> n >> k >> b;
    vector<int> blocks(n + 1, 0);

    for(int i = 0; i < b; i++) {
        cin >> ans;
        blocks[ans] += 1;
    }

    for(int i = 1; i <= n; i++) blocks[i] += blocks[i - 1];

    ans = 1e9;
    for(int i = 0; i <= n - k; i++) 
        ans = min(ans, blocks[i + k] - blocks[i]);

    cout << ans << '\n';

    return 0;
}
