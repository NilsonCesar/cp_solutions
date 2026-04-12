#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int c, p, f;
    cin >> c >> p >> f;
    cout << (c * f <= p ? "S" : "N") << '\n';
    return 0;
}
