#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int p, b, r;
    cin >> p;
    vector<int> P(p);

    for (int i = 0; i < p; i++)
        cin >> P[i];
    cin >> r >> b;

    r -= b;

    for (int i = 0; i < p; i++ ) {
        if (r <= P[i]) {
            cout << "NAO" << '\n';
            return 0;
        }
    }

    cout << "SIM" << '\n';

    return 0;
}
