#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int number = 1, ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cost = number;
                if (number - n >= 1) {
                    cost += number - n;
                }
                if (number + n <= n * n) {
                    cost += number + n;
                }

                if (j - 1 >= 1) {
                    cost += number - 1;
                }

                if (j + 1 <= n) {
                    cost += number + 1;
                }

                ans = max(ans, cost);
                number++;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
