#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    if (r < a || l > b) {
        cout << (b - a) * y << '\n'; 
    } else {
        int int_l = max(l, a);
        int int_r = min(r, b);
        cout << (int_r - int_l) * x + (b - a - int_r + int_l) * y << '\n';
    }

    return 0;
}
