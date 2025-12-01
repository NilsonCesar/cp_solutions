#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int k, n;
string s;

void solve(int ini, int fim) {
    for (int i = ini + k - 1; i < fim; i += k) {
        if (i == fim - 1) s[i - 1] ^= 1;
        else s[i] ^=1;
    }
}

int main(void) {_
    cin >> k >> s;
    n = (int) s.size();

    if (k == 2) {
        int distA = 0, distB = 0, flag = 0;
        for (int i = 0; i < n; i++) {
            distA += (s[i] - '0') % (2) != (i % 2);
            distB += (s[i] - '0') % (2) == (i % 2);
        }

        cout << min(distA, distB) << ' ';
        for (int i = 0; i < n; i++) {
            if (distA <= distB) {
                cout << (char) (((s[i] - '0') % 2 != i % 2) ? s[i] ^ 1 : s[i]);
            } else {
                cout << (char) (((s[i] - '0') % 2 == i % 2) ? s[i] ^ 1 : s[i]);
            }
        }
        cout << '\n';
    } else {
        int resp = 0, fim;
        for (int ini = 0; ini < n; ini = fim) {
            for (fim = ini; fim < n && s[fim] == s[ini]; fim++) ;
            resp += (fim - ini) / k;
            solve(ini, fim);
        }
        cout << resp << ' ' << s << '\n';
    }

    return 0;
}
