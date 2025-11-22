#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int m[11];
int main(void) {_
    int a, b, c; 
    cin >> a >> b >> c;
    m[a]++;
    m[b]++;
    m[c]++;

    if (m[5] == 2 && m[7] == 1) cout << "YES";
    else cout << "NO";
    cout << '\n';

    return 0;
}
