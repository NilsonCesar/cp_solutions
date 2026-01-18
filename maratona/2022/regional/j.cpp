#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, c;
    cin >> n;
    int john = 0, mary = 0;
    vector<int> cards(14, 4);

    for (int i = 0; i < 2; i++) {
        cin >> c;
        john += min(c, 10);
        cards[c]--;
    }

    for (int i = 0; i < 2; i++) {
        cin >> c;
        mary += min(c, 10);
        cards[c]--;
    }

    for (int i = 0; i < n; i++) {
        cin >> c;
        mary += min(c, 10);
        john += min(c, 10);
        cards[c]--;
    }

    for (int i = 1; i <= 13; i++) {
        if (!cards[i]) continue;
        int p = min(i, 10);
        if (john + p > 23 && mary + p <= 23) {
            cout << p << '\n';
            return 0;
        } else if (mary + p == 23) {
            cout << p << '\n';
            return 0;
        }
    }
    
    cout << -1 << '\n';

    return 0;
}
