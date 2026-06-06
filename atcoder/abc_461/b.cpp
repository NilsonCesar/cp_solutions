#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, a, b;
    cin >> n;
    vector<int> axes(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        axes[a] = i;
    }

    for (int i = 1; i <= n; i++) 
    {
        cin >> b;
        if (axes[i] != b) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}
