#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m;
    cin >> n >> m;
    int ans = 0;

    while(m != 0) {
        m = n % m;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
