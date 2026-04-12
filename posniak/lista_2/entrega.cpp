#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    

    if (c1 + c2 < c3) {
        cout << 1;
    } else if (c3 > c2 && c2 > c1) {
        cout << 1;
    } else if (c3 > c2 || c3 > c1) {
        cout << 2;
    } else {
        cout << 3;
    }
    cout << '\n';

    return 0;
}
