#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;

    vector<int> zeros, a(n);
    zeros.push_back(INF);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zeros.push_back(i);
        }
    }
    zeros.push_back(INF);
    int j = 0, k = 1;

    for (int i = 0; i < n; i++) { 
        // cout << zeros[j] << ' ' << zeros[k] << ' ' << i << '\n';
        cout << min(9, min(abs(zeros[j] - i), abs(zeros[k] - i)));
        if (i != n - 1) cout << ' ';
        if (i >= zeros[k]) {
            k++;
            j++;
        }
    }
    cout << '\n';

    return 0;
}
