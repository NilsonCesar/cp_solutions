#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    cin >> t;
    while (t--) {
        int n, qa = 0, qb = 0, w;
        cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] != b[i - 1]) {
                if (i % 2) {
                    qa++;
                    w = 1;
                } else {
                    qb++;
                    w = 2;
                }
            }
        }

        if ((qa + qb) % 2) cout << (w == 1 ? "Ajisai" : "Mai");
        else cout << "Tie";
        cout << '\n';   
    }

    return 0;
}
