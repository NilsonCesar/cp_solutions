#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        cout << (((n - 2) / 3) + ((n - 2) % 3 > 0)) * (((m - 2) / 3) + ((m - 2) % 3 > 0)) << '\n';
    }
    return 0;
}
