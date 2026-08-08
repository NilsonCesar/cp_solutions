#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, k;
bool v[MAXN];
vector<int> l[MAXN];
int resp;

int dfs(int x, int p, int dist) {
    int ret = v[x] ? dist : 0;

    for (int i = 0; i < (int) l[x].size(); i++) {
        if (l[x][i] != p) {
            int r = dfs(l[x][i], x, dist + 1);
            if (r > 0)
                resp += 2;
            ret = max(ret, r);
        }
    }

    return ret;
}

int main(void) {_
    cin >> n >> k;
    int t, a, b;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        v[i] = (t > k);
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int maxh = dfs(1, 0, 0);
    cout << resp - maxh << '\n';

    return 0;
}
