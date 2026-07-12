#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n;

bool valid(int i, int j) {
    if (j > n) return false;
    string ans;
    cout << "? " << i << " " << j << '\n' << flush;
    cin >> ans;
    return ans == "Yes";
}

int main(void) {_
    cin >> n;
    int i = 1, j = 2;
    long long ans = 0;

    while (i < n && j <= n) {
        int cnt = j - 1 - i;
        while(valid(i, j)) {
            j++;
            cnt++;
        }
        ans += cnt;
        i++;
        if (i == j) j++;
        if (j > n) j = n;
    }

    cout << "! " << ans << '\n' << flush;

    return 0;
}
