#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);

map<long long, int> expo;

int main(void) {_
    string s;
    cin >> s;
    int n = s.size();
    long long x = 0;
    for (int i = 0; i < min(10, n); i++) {
        x = x * 10 + (s[i] - '0');
    }

    for (long long i = 2; i*i <= x; i++) {
        while(x % i == 0) {
            x /= i;
            expo[i]++;
        }
    }

    if (x > 1) {
        expo[x]++;
    }

    if (n - 10 > 0) {
        expo[2] += max(n - 10, 0);
        expo[5] += max(n - 10, 0);
    }
    
    cout << expo.size() << '\n';

    for (auto p: expo)
        cout << p.first << ' ' << p.second << '\n';

    return 0;
}
