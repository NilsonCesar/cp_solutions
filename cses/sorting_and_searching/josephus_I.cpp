#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, flip = 0;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    
    while(!q.empty()) {
        if (flip) {
            cout << q.front() << ' ';
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
        flip = !flip;
    }
    cout << '\n';

    return 0;
}
