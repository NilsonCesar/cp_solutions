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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, bool> deny;
    map<int, int> idx;
    vector<int> ans(n);
    int i = 0, j = 0;
    while(j < n) {
        if (a[j] < 0) {
            deny[-a[j]] = true;
            idx[-a[j]] = j;
        } else if (deny[a[j]] && idx[a[j]] >= i) {
            int jj = idx[a[j]];
            while (jj >= i) {
                ans[jj] = j - jj;
                jj--;
            }
            i = idx[a[j]] + 1;
        }
        j++;
    }
    while (j > i) {
        j--;
        ans[j] = n - j;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
