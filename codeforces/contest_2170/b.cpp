#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        long long sum_b = 0, b, lim = 0;

        for (int i = 0; i < n; i++) {
            cin >> b;
            sum_b += b;
            lim += b != 0;
        }
        
        cout << min(lim, sum_b - n + 1) << '\n';
        
    }

    return 0;
}
