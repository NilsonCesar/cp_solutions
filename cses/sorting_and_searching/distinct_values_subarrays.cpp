#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, a, l = 0;
    cin >> n;
    map<int, int> m;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        cin >> a;
        if (m.find(a) != m.end() && m[a] >= l) {
            l = m[a] + 1;
        }
        m[a] = i;
        ans += i - l + 1;
    }
    
    cout << ans << '\n';

    return 0;
}
