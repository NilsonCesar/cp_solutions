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
    long long n, a, b, c;
    cin >> n;
    vector<long long> d(n), ds(n), s(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        d[i] = min(a + b, min(a + c, b + c)) + 2ll;
        ds[i] = d[i];
        s[i] = a + b + c;
    }

    sort(ds.begin(), ds.end());
    
    for (int i = 0; i < n; i++) {
        long long number = upper_bound(ds.begin(), ds.end(), s[i]) - ds.begin();
        cout << (s[i] >= d[i] ? number - 1 : number) << ' ';
    }
    cout << '\n';

    return 0;
}
