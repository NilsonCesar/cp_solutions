#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<char> v;
    for (char c: s) v.push_back(c);

    for (int i = 0; i < n; i++) {
        set<char> u;
        for (int j = 0; j < i; j++) u.insert(s[j]);
        int l = i;
        bool valid = (int) u.size() == (n - i);
        for (char c: u) {
            // cout << c << ' ';
            if (c == v[l]) {
                l++;
            } else {
                valid = false;
                break;
            }
        }
        // cout << '\n';

        if (valid) {
            cout << i << '\n';
            break;
        }

    }
}