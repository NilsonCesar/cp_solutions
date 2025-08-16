#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int q, op, x;
    cin >> q;
    priority_queue<int> balls;
    while(q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            balls.push(-x);
        } else {
            cout << -balls.top() << '\n';
            balls.pop();
        }
    }

    return 0;
}
