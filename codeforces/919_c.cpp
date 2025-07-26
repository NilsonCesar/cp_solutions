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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    unsigned long long ans = 0;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') continue;
            if (m - j >= k) {
                int count = 0;
                while (m > j && a[i][j] != '*') {
                    j++;
                    count++;
                }
                if (count >= k) {
                    ans += count - k + 1;
                }
            }
        }
    }

    if (k != 1) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (a[i][j] == '*') continue;
                if (n - i >= k) {
                    int count = 0;
                    while (n > i && a[i][j] != '*') {
                        i++;
                        count++;
                    }
                    if (count >= k) {
                        ans += count - k + 1;
                    }
                }
            }
        }
    } 

    cout << ans << '\n';
    
    return 0;
}
