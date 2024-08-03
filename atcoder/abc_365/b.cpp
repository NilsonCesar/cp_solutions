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

    int n, b1 = -1, b2 = -1;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(b1 == -1) b1 = i;
        else if(a[i] > a[b1]) {
            b2 = b1;
            b1 = i;
        } else if(b2 == -1) b2 = i;
        else if(a[i] > a[b2]) b2 = i;
    }

    cout << b2 + 1 << '\n';

    return 0;
}
