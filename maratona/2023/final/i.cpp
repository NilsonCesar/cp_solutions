#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000007

long long externalInversions(string s) {
    map<char, int> freq;
    int total = s.size();
    for (int i = 0; i < s.size(); i++)
        freq[s[i]]++;
    sort(s.begin(), s.end()); 
    long long res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        res += total - freq[s[i]];
        total -= freq[s[i]];
        freq[s[i]] = 0;
    }
    return res;
}

long long countAndMerge(string& s, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;

    string s1, s2;
    s1.resize(n1);
    s2.resize(n2);
    for (int i = 0; i < n1; i++)
        s1[i] = s[i + l];
    for (int j = 0; j < n2; j++)
        s2[j] = s[j + m + 1];

    long long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (s1[i] <= s2[j])
            s[k++] = s1[i++];

        else {
            s[k++] = s2[j++];
            res += (n1 - i);
        }
    }

    while (i < n1) 
        s[k++] = s1[i++];
    while (j < n2)
        s[k++] = s2[j++];
    return res;
}

long long countInversions(string& s, int l, int r) {
    long long res = 0;
    if (l < r) {
        int m = (l + r) / 2;
        res += countInversions(s, l, m);
        res += countInversions(s, m + 1, r);
        
        res += countAndMerge(s, l, m, r);
    }
    return res;
} 

long long internalInversions(string s) {
    return countInversions(s, 0, s.size() - 1);
}

int main(void) {_
    long long n;
    string s;
    cin >> s >> n;
    long long ext = externalInversions(s) % MOD;
    long long pair = 0;
    if (n % 2 == 0) pair = ((n / 2) % MOD) * ((n - 1) % MOD);
    else pair = ((n - 1) / 2ll) % MOD * (n % MOD);
    ext *= pair % MOD;
    cout << ((internalInversions(s) % MOD) * (n % MOD) + (ext % MOD)) % MOD << '\n';
    return 0;
}
