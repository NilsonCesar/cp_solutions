#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

vector<long long> pa, pb, pc;

long long f(int x) {
    return pa[x] - pb[x];
}

long long g(int y) {
    return pb[y] - pc[y];
} 

int main(void) {_
    long long max_f = -((long long) INF) * 100, a, ans = -INF;
    int n;
    cin >> n;
    pa.resize(n + 1, 0);
    pb.resize(n + 1, 0);
    pc.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        pa[i] = pa[i - 1] + a;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a;
        pb[i] = pb[i - 1] + a;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a;
        pc[i] = pc[i - 1] + a;
    }

    max_f = f(1);

    for (int y = 2; y < n; y++) {
        ans = max(max_f + g(y) + pc[n], ans);
        if (max_f < f(y)) max_f = f(y);
    }

    cout << ans << '\n';

    return 0;
}
