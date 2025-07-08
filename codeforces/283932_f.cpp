#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n, m;
string t, p;
vector<int> a;

bool check(int x) {
    unordered_set<int> del;
    for (int i = 1; i <= x; i++) del.insert(a[i] - 1);
    string temp = "";
    for (int i = 0; i < n; i++) 
        if (del.find(i) == del.end()) temp += t[i];
    int i = 0, j = 0, n_temp = (int) temp.size();

    while (i < n_temp && j < m) {
        while (i < n_temp && temp[i] != p[j]) i++;
        if (temp[i] == p[j]) {
            i++; j++;
        }
    }

    return j == m;
} 

int main(void) {
    mainIO();
    cin >> t >> p;
    n = (int) t.size(), m = (int) p.size();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n - m + 1, mid;

    if (m == 0) {
        cout << n << '\n';
        return 0;
    }

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
    
    return 0;
}
