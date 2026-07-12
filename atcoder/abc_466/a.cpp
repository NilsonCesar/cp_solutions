#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a;
    cin >> n;
    bool isAlwaysNegative = true;
    
    for(int i = 0; i < n; i++) {
        cin >> a;
        if (a >= 0) isAlwaysNegative = false;
    }

    cout << (isAlwaysNegative ? "Yes" : "No") << '\n';

    return 0;
}
