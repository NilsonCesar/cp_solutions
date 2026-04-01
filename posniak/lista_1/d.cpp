#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    if (m2 < m1) {
        m2 += 60;
        h2--;
    }

    if (s2 < s1) {
        s2 += 60;
        m2--;
    }

    cout << (h2 - h1) * 60 * 60 + (m2 - m1) * 60 + (s2 - s1) << " segundo(s)" << '\n';


    return 0;
}
