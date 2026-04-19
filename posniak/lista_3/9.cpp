#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int x, y;
    cin >> x >> y;

    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        cout << "dentro";
    } else cout << "fora";
    cout << '\n';
    
    return 0;
}
