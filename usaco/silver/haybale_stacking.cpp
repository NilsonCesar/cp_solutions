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
    int n, k, l, r;
    cin >> n >> k;
    vector<long long> stacks(n + 2, 0);
    for(int i = 0; i < k; i++) {
        cin >> l >> r;
        stacks[l] += 1;
        stacks[r + 1] -= 1; 
    }

    for(int i = 1; i <= n; i++) stacks[i] += stacks[i - 1];
    sort(stacks.begin(), stacks.end());

    cout << stacks[(n / 2) + 1] << '\n';

    return 0;
}
