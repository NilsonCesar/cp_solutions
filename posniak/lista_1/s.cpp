#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    float s, v;
    string vend;
    cin >> vend;
    cin >> s >> v;
    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << s + v * 0.15 << '\n';
    return 0;
}
