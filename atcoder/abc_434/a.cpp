#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int w, b;
    cin >> w >> b;
    w *= 1000;
    cout << 1 + w / b << '\n';
    return 0;
}
