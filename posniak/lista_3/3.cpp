#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int x00, y00, x10, y10;
    int x01, y01, x11, y11;

    cin >> x00 >> y00 >> x10 >> y10;
    cin >> x01 >> y01 >> x11 >> y11;

    int x_min = max(x00, x01);
    int x_max = min(x10, x11);
    int y_min = max(y00, y01);
    int y_max = min(y10, y11);

    cout << (x_min <= x_max && y_min <= y_max ? 1 : 0) << '\n';
    return 0;
}
