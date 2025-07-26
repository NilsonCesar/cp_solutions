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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unsigned long long ans = 0;
    int i = 0, j = 0;
    map<int, int> nums;
    nums[a[i]]++;
    int distincts = 1;

    while (i < n && j < n) {
        if (distincts <= k) {
            ans += j - i + 1;
            j++;
            nums[a[j]]++;
            if (nums[a[j]] == 1) {
                distincts++;
            }
        } else {
            while(distincts > k) {
                nums[a[i]]--;
                if (nums[a[i]] == 0) {
                    distincts--;
                }
                i++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
