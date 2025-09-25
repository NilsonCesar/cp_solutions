#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define MAXN 100100
#define INF 2e9


int n, k;
int v[MAXN], pref[MAXN], suf[MAXN];

int main(void) {
    mainIO();
    cin >> n >> k;
    pref[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = min(v[i], pref[i - 1]); 
    }
    suf[n + 1] = INF;
    for (int i = n; i > 0; i--)
        suf[i] = min(v[i], suf[i + 1]);
    
    multiset<int> s;

    int resp = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(v[i] + i);
        if(i - k > 0) 
            s.erase(s.find(v[i - k] + i - k));
        int r = *s.begin() - i + k;
        if (i - k > 0) 
            r = min(r, pref[i - k]);
        if (i < n)
            r = min(r, suf[i + 1]);
        resp = max(resp, r);
    }

    cout << resp << '\n';

    return 0;
}
