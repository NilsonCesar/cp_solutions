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
    int n, q, head = 0, p, x;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    while(q--) {
        cin >> x >> p;
        if (x == 1) {
            cin >> x;
            a[(head + p - 1) % n] = x;
        } 
        else if (x == 2) {
            // cout << "idx: " << (head + p - 1) % n << '\n';
            cout << a[(head + p - 1) % n] << '\n';
        }
        else {
            head = (head + p) % n;
            // cout << "Head: " << head << '\n';
        }
    }

    return 0;
}
