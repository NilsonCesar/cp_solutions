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
    int n;
    cin >> n;
    vector<int> nums(n);
    long long ans = 0, num;
    for(int i = 0; i < n; i++) 
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    num = nums[n / 2];

    for(int i = 0; i < n; i++)
        ans += abs(num - nums[i]);
    cout << ans << '\n';    
    return 0;
}