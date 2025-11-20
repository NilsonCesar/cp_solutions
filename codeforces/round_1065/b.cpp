#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100000+7

int main(void) {_
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (a[0] == -1 && a[n - 1] != -1) a[0] = a[n - 1];
        else if (a[n - 1] == -1 && a[0] != -1) a[n - 1] = a[0];
        else if (a[n - 1] == -1 && a[0] == -1) a[0] = a[n - 1] = 0;
        cout << abs(a[n - 1] - a[0]) << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) a[i] = 0;
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
