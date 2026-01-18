#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n = 8, ans = 0, bit;

    while(n--) {
        cin >> bit;
        if (bit == 9) {
            ans = 1;
        }
    }

    cout << (ans ? 'F' : 'S') << '\n';

    return 0;
}
