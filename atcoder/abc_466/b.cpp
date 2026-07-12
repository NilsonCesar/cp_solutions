#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, a, b;
    cin >> n >> m;
    map<int, int> max_colors;

    for (int i = 1; i <= m; i++) max_colors[i] = -1;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        max_colors[a] = max(max_colors[a], b);
    } 

    for (int i = 1; i <= m; i++) cout << max_colors[i] << ' ';
    cout << '\n';

    return 0;
}
