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
    int n, ans1 = -1, ans2 = -1;
    cin >> n;
    vector<int> a(n);
    map<int, int> f;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    sort(a.begin(), a.end());

    for (int i = n - 1; i >= 0; i--) {
        int c = a[i];
        if (f[a[i]] + n - i - 1 >= a[i]) {
            ans1 = a[i];
            break;
        } else {
            while (i >= 0 && a[i] == c) i--;
            if (i < 0) break;
            i++;
        }
    }

    for (int i = n; i >= 0; i--) {
        int acc = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] >= i) acc++;
            else break;
        }

        if (acc >= i) {
            ans2 = i;
            break;
        }
    }

    cout << max(ans1, ans2) << '\n';

    return 0;
}
