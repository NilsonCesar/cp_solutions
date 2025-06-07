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
    int n, swap = 0, k = 0;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> swaps;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int min_a = a[i], min_i = i;
        for (int j = i + 1; j < n; j++) 
            if (min_a > a[j]) {
                min_a = a[j];
                min_i = j;
            }
        
        if (min_i != i) {
            k++;
            swaps.push_back({i, min_i});
            int c = a[i];
            a[i] = a[min_i];
            a[min_i] = c;
        }
    }

    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << swaps[i][0] << ' ' << swaps[i][1] << '\n'; 


    return 0;
}
