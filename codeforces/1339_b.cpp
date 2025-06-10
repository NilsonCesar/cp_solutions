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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int i = 0, j = n - 1, k = n - 1;
        vector<int> a(n), ans(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        sort(a.begin(), a.end());

        while (i <= j) {
            if (i == j) {
                ans[0] = a[i];
                break;
            }
            ans[k--] = a[i++];
            ans[k--] = a[j--];
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
