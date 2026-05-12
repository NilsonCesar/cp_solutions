#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    cin >> t;

    while(t--) {
        int n, m, h, b, c;
        cin >> n >> m >> h;
        vector<long long> a(n), copy_a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            copy_a[i] = a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b >> c;
            a[b - 1] += c;
            if (a[b - 1] > h) {
                for (int i = 0; i < n; i++) {
                    a[i] = copy_a[i];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
