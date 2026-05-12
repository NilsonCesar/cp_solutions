#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, v;

    while(cin >> n >> v && n && v) {
        int acc = 0, pos = 0;
        for (int k = 1; k <= v; k++) {
            // cout << "v = " << k << '\n';
            for (int i = k; i >= 0; i--) {
                for (int j = 1; j <= i; j++) {
                    acc += i;
                    if (acc == n) {
                        pos = 1;
                        break;
                    }
                    // cout << acc << '\n';
                }
                if (pos) break;
            }
            acc = 0;
            if (pos) break;
        }

        cout << (pos ? "possivel" : "impossivel") << '\n';
    }

    return 0;
}
