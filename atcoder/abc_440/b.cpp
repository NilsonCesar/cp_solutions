#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, h;
    priority_queue<pair<int, int>> horses;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        horses.push({-h, i + 1});
    }
    for (int i = 0; i < 3; i++) {
        cout << horses.top().second << ' ';
        horses.pop();
    }
    cout << '\n';

    return 0;
}
