#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a, r = 0;
    cin >> n;
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a;
        r += (s.find(a - 1) == s.end());
        s.insert(a);
    }

    cout << r << '\n';

    return 0;
}
