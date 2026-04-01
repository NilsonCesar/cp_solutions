#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int a, b, c;
    cin >> a >> b >> c;
    int delta = b * b - 4 * a * c;
    float x1 = (-b + sqrt(delta * 1.0)) * 1.0 / (2.0 * a);
    float x2 = (-b - sqrt(delta * 1.0)) * 1.0 / (2.0 * a);
    cout << fixed << setprecision(3);
    cout << x1 << ' ' << x2 << '\n';

    return 0;
}
