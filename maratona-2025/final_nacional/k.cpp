#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 1e8

vector<pair<int, int>> v;
long long x, y, xmin, xmax, ymin, ymax; 

long long test(long long x, long long y) {
    return (max(xmax, x) - min(xmin, x) + 1) * (max(ymax, y) - min(ymin, y) + 1);  
}

int main(void) {_
    int n, k;
    cin >> n >> k;
    xmin = INF, xmax = -INF, ymin = INF, ymax = -INF; 
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
        xmin = min(x, xmin);
        xmax = max(x, xmax);
        ymin = min(y, ymin);
        ymax = max(y, ymax);
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    long long resp = (xmax - xmin) * (ymax - ymin);

    for (auto [x, y]: v) {
        resp = max(resp, test(x + k, y + k));
        resp = max(resp, test(x + k, y - k));
        resp = max(resp, test(x - k, y + k));
        resp = max(resp, test(x - k, y - k));
    }

    long long diffx = xmax - xmin + 1, diffy = ymax - ymin + 1;

    for (int i = 0; i <= k; i++) 
        resp = max(resp, (diffx + i) * (diffy + k - i));

    cout << resp << '\n';

    return 0;
}
