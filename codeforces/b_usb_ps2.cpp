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
    long long a, b, c, m, val, ans_qtd = 0, ans_val = 0;
    string type;
    cin >> a >> b >> c >> m;
    vector<pair<int, string>> e;
 
    for(int i = 0; i < m; i++) {
        cin >> val >> type;
        e.push_back({val, type});
    }
    
    sort(e.begin(), e.end());
    
    for(int i = 0; i < m; i++) {
        val = e[i].first, type = e[i].second;
        
        if(type == "USB") {
            if(a || c) {
                ans_qtd++;
                ans_val += val;
            }
            if(a) a--;
            else if(c) c--;
        } else {
            if(b || c) {
                ans_qtd++;
                ans_val += val;
            }
            if(b) b--;
            else if(c) c--;
        }
    }
    
    cout << ans_qtd << ' ' << ans_val << '\n';
 
    return 0;
}
