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
    int n, ans = 1e6;
    set<char> p;
    cin >> n;
    string s;
    cin >> s;
    
    for(int i = 0; i < n; i++)
        p.insert(s[i]);
    
    int i = 0, j = -1 + (int) p.size();
    
    map<char, int> freq;
    int qtd = 0;
    
    for(char c : p) freq[c] = 0;
    for(int i = 0; i <= j; i++) freq[s[i]] += 1;
    for(char c : p) 
        if(!freq[c]) 
            qtd++;
            
    if(!qtd) {
        cout << j + 1 << '\n';
        return 0;
    }
    
    while(i < n && j < n) {
        if(!qtd) {
            ans = min(ans, j - i + 1);
            freq[s[i]] -= 1;
            if(!freq[s[i]]) qtd++;
            i++;
        }
        else if(j <= n - 1) {
            j++;
            freq[s[j]]++;
            if(freq[s[j]] == 1) qtd--;
        }
    }

    cout << ans << '\n';

    return 0;
}
