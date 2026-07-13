#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 2), b, c;
    for (int i = 0; i < n + 2; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long s, m;
    s = a.back();
    int l = 0, r = n;

    while(a[l] + a[r] != s) {
        if (a[l] + a[r] < s) l++;
        else r--;
    }

    // supondo m = a[l];

    long long sum_l = a[l];
    bool is_l_m = true;
    m = a[l];

    for (int i = 0; i < n + 1; i++) {
        if (i == l || i == r) continue;
        b.push_back(a[r] - (a[i] - m));
        if (a[r] - (a[i] - m) < 0) is_l_m = false; 
        sum_l += a[r] - (a[i] - m);
    }

    b.push_back(m);

    if (is_l_m && sum_l == s) {
        cout << s << ' ' << m << '\n';
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
   
    // supondo m = a[r];

    long long sum_r = a[r];
    m = a[r];

    for (int i = 0; i < n + 1; i++) {
        if (i == l || i == r) continue;
        c.push_back(a[l] - (a[i] - m)); 
        sum_r += a[l] - (a[i] - m);
    }

    c.push_back(m);
    
    cout << s << ' ' << m << '\n';
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';

    return 0;
}