#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int a, b, z;
    cin >> a >> b >> z;
    if (a - b * z < 0 || (a - b * z) % (z - 1) != 0) cout << "No";
    else cout << "Yes";
    cout << '\n';

    return 0;
}
