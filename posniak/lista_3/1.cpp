#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int d;
    cin >> d;

    if (d <= 800) cout << 1;
    else if (d <= 1400) cout << 2;
    else cout << 3;
    cout << '\n';

    return 0;
}
