#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

bool is_palindrome(int n, string s) {
    // cout << "here " <<  s << '\n';
    bool have_palindrome;
    for(int i = 0; i < (int) s.size(); i++) {
        if(i + n > (int) s.size()) break;
        have_palindrome = true;
        
        string a = string(s.begin() + i, s.begin() + (i + n));
        string b = string(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // cout << "here " << a << ' ' << b << '\n';
        for(int j = 0; j < (int) a.size(); j++)
            if(a[j] != b[j]) 
                have_palindrome = false;

        if(have_palindrome) return true;
    }

    // cout << s << '\n';
    return false;
}

int main(void) {
    mainIO();
    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());

    do {
        ans += !is_palindrome(k, s);
    } while(next_permutation(s.begin(), s.end()));

    cout << ans << '\n';

    return 0;
}
