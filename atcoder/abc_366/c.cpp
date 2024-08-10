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

    map<long long, unsigned long long> numbers;
        
    int q, op, x, len = 0;
    cin >> q;
    
    while(q--) {
        cin >> op;
        
        if(op == 3) cout << len << '\n';
        else if(op == 1) {
            cin >> x;
            if(numbers.find(x) != numbers.end()) numbers[x] += 1;
            else numbers[x] = 1;
            if(numbers[x] == 1) len++;
        } else {
            cin >> x;
            numbers[x] = max(numbers[x] - 1, 0ull);
            if(numbers[x] == 0) len--;
        }
    }

    return 0;
}
