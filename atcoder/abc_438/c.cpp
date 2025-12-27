#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, ans, a;
    cin >> n;
    ans = n;
    vector<int> d, cnt;
    d.push_back(0);
    cnt.push_back(0);

    while(n--) {
        cin >> a;
        if (d.back() == a) {
            cnt[-1 + (int) cnt.size()]++;
        } else {
            d.push_back(a);
            cnt.push_back(1);
        }

        if (cnt.back() == 4) {
            cnt[-1 + (int) cnt.size()] -= 4;
            ans -= 4;
        }

        if (cnt.back() == 0) {
            cnt.pop_back();
            d.pop_back();
        }
    }

    cout << ans << '\n';

    return 0;
}
