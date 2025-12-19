#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int solve(int n, int k) {
    if (n == 1) return 1;
    if (k <= n / 2) return 2 * k;
    if (n % 2 == 0) return 2 * solve(n - n / 2, k - n / 2) - 1;
    int resp = solve(n - n / 2, k - n / 2);
    if (resp == 1) return n;
    else return 2 * resp - 3;
}

int main(void) {_
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}
