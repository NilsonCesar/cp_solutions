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

    int n, x, num;
    cin >> n >> x;
    vector<vector<int>> a(n);
    for(int i = 1; i <= n; i++) {
        cin >> num;
        a[i - 1] = {num, i};
    }
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) {
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = a[i][0] + a[j][0] + a[k][0];
            if(sum == x) {
                cout << a[i][1] << ' ' << a[j][1] << ' ' << a[k][1] << '\n';
                return 0;
            } 
            else if(sum < x) j++;
            else k--;
        }
    }
    
    cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}
