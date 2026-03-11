#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k, l, r;
    cin >> n >> k;
    vector<int> haybale(n + 7, 0), sumpref(n + 7, 0);
    while(k--) {
        cin >> l >> r;
        haybale[l]++;
        haybale[r + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        sumpref[i] += sumpref[i - 1] + haybale[i];
    }

    sort(sumpref.begin(), sumpref.begin() + n + 1);

    cout << sumpref[n / 2 + 1] << '\n';

    return 0;
}
