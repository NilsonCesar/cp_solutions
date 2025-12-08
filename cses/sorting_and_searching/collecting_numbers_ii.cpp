#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
int n, m;
map<int, int> num;


int contribute(int val) {
    if (val < 1 || val >= n) return 0;

    if (num[val + 1] < num[val]) return 1;

    return 0;
}

int main(void) {_
    int r = 0, p, q;
    cin >> n >> m;
    vector<int> a(n + 7);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r += (num.find(a[i] - 1) == num.end());
        num[a[i]] = i;
    }
    num[0] = 0;
    num[n + 1] = n + 1;

    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        int u = a[p], v = a[q];

        set<int> check;
        check.insert(u - 1), check.insert(u);
        check.insert(v - 1), check.insert(v);

        for (int val : check) r -= contribute(val);

        swap(a[p], a[q]);
        num[u] = q;
        num[v] = p;

        for (int val : check) r += contribute(val);

        cout << r << '\n';
    }

    return 0;
}
