#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int a, b, c;
    cin >> a >> b >> c;

    if ((b - a) < (c - b)) {
        cout << 1;
    } else if (b - a == c - b) cout << 0;
    else cout << -1;
    cout << '\n';

    return 0;
}
