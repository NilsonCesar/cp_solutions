#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, ans = 0, b;
    cin >> n;
    multiset<int> s;

    while(n--) {
        cin >> b;
        if (s.find(b + 1) == s.end()) ans++;
        else {
            s.erase(s.find(b + 1));
        }
        s.insert(b);
    }

    cout << ans << '\n';

    return 0;
}
