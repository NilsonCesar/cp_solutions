#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MOD 1000000007

int main(void) {_
    long long pv = 1, pf = 0, s = 0, x;
    int n;
    cin >> n;
    char op;

    while(n--) {
        cin >> op >> x;
        if (op == '?') {
            cout << (((x * pv) % MOD) + (pf + s) % MOD) % MOD << '\n';
        } else if (op == '+') {
            s = (s + x) % MOD;
        } else {
            pf = ((pf * x) % MOD) + ((s * x) % MOD); 
            pv = (pv * x) % MOD;
            s = 0;
        }
    }

    return 0;
}