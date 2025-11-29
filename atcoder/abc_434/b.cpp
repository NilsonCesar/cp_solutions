#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, a, b;
    cin >> n >> m;
    map<int, int> t;
    vector<int> ts(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        t[a] += b;
        ts[a]++;
    }

    cout << setprecision(15);
    for (int i = 1; i <= m; i++) {
        cout << (t[i] * 1.0) / ts[i] << '\n';
    }
    return 0;
}
