#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, l;

    while (cin >> n) {
        int ans = -1;

        for (int i = 0; i < n; i++) {
            cin >> l;
            ans = max(l, ans);
        }

        if (ans < 10) {
            cout << 1;
        } else if (ans < 20) {
            cout << 2;
        } else {
            cout << 3;
        }
        cout << '\n';
    }


    return 0;
}
