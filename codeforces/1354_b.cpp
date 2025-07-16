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
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int one = -1, two = -1, three = -1;
        int ans = 2e6;

        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '1') 
                one = i;
            if (s[i] == '2')
                two = i;
            if (s[i] == '3')
                three = i;
            
            if (one != -1 and two != -1 and three != -1)
                ans = min(ans, 1 + max(one, max(two, three)) - min(one, min(two, three)));
        }

        cout << (ans != 2e6 ? ans : 0) << '\n';
    }

    return 0;
}
