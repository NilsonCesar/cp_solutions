#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int a, b;
    cin >> a >> b;

    if (a % 2 != 0) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    int delta = (2 - a / 2) * (2 - a / 2) - 4 * b;

    // cout << "delta: " << delta << '\n';
    if (delta < 0) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    int i = 0;
    while(i * i < delta) i++;
    // cout << "sqrt delta: " << i << '\n';
    if (i * i != delta) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    b = (2 - a / 2);
    if ((-b + i) % (2) != 0) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    int w = (-b + i) / (2);
    int h = a / 2 - 2 - w;
    cout << min(h, w) + 2 << ' ' << max(h, w) + 2 << '\n';

    return 0;
}
