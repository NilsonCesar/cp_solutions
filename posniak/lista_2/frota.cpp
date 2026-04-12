#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    double a, g, ra, rg;
    cin >> a >> g >> ra >> rg;
    cout << (ra * g <= rg * a ? "G" : "A") << '\n';
    return 0;
}
