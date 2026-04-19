#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    vector<int> a(5), b(5);
    int n = 5;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cout << "N" << '\n';
            return 0;
        }
    }
    cout << "Y" << '\n';


    return 0;
}
