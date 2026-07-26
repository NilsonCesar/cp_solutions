#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define LIM 1000000ll

string s, t;
long long p, q;

char charac(long long pos, string &a, long long exp, string &b) {
    if (pos < a.size() * exp) {
        return a[pos % (a.size())];
    }
    return b[(pos - a.size() * exp) % (b.size())];
}

char comp() {
    int lim = min(LIM, (long long) s.size()*p + (long long) t.size()*q);
    for (int i = 0; i < lim; i++) {
        char c1 = charac(i, s, p, t);
        char c2 = charac(i, t, q, s);
        if (c1 != c2) {
            return c1 < c2 ? '<' : '>';
        }
    }
    return '=';
}

int main(void) {_
    cin >> s >> t >> p >> q;
    cout << comp() << '\n';
    return 0;
}
