#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 1000007

int ans = MAXN;

vector<int> memo(MAXN, INF);

int ith_digit(int n, int i) {
    return (n / ((int) pow(10, i))) % 10;
}

int main(void) {_
    int n;
    cin >> n;
    
    memo[0] = 0;

    for (int i = 1; i <= 9; i++) memo[i] = 1;

    for (int x = 10; x <= n; x++) {
        int nLen = (int) log10(x) + 1;
        for (int i = 0; i <= nLen; i++) {
            int d = ith_digit(x, i);
            memo[x] = min(memo[x], memo[x - d] + 1);
        }
    }

    cout << memo[n] << '\n';

    return 0;
}
