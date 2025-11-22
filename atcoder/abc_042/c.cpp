#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int k, num;
    int n;
    cin >> n >> k;
    vector<int> d(10, 1);
    for (int i = 0; i < k; i++){
        cin >> num;
        d[num] = 0;
    }

    while(true) {
        string s = to_string(n);
        bool valid = true;
        for (int i = 0; i < (int) s.size(); i++) {
            if (!d[s[i] - '0']) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << n << '\n';
            break;
        }
        n++;
    }
    
    return 0;
}
