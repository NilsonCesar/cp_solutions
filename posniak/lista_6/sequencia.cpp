#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, b, last = -1;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> b;
        if (b != last) {
            ans++;
            last = b;
        }
    }
    cout << ans << '\n';

    return 0;
}
