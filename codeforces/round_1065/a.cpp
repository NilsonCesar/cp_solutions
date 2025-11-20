#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100000+7

int main(void) {_
    int n, t;
    cin >> t;

    while(t--) {
        cin >> n;
        set<pair<int, int>> ans;

        for (int i = 0; i <= 100; i++) 
            for (int j = 0; j <= 100; j++)
                if (i * 2 + j * 4 == n)
                    ans.insert({i, j});
        cout << (int) ans.size() << '\n';
    }

    return 0;
}
