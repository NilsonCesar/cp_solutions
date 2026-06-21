#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, q, t;
    cin >> n;
    vector<int> h(n), l(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> l[i];
    }

    vector<int> suf_max(n);

    suf_max[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], h[i]);
    }

    cin >> q;

    while(q--) {
        cin >> t;
        int idx = lower_bound(l.begin(), l.end(), t + 1) - l.begin();
        cout << suf_max[idx] << '\n';
    }

    return 0;
}
