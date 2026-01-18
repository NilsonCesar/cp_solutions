#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, c, best_match = 0;
    cin >> n >> c;
    vector<string> pos_solutions;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int aster = s.find('*');
        for (char ch = 'a'; ch <= 'z'; ch++) {
            s[aster] = ch;
            pos_solutions.push_back(s);
        }
    }

    sort(pos_solutions.begin(), pos_solutions.end());

    int best = 0;
    string s;

    for (int i = 0; i < (int) pos_solutions.size(); i++) {
        int tmp_best = 0, j = i;
        string candidate = pos_solutions[i];
        while(j < (int) pos_solutions.size() && candidate == pos_solutions[j]) { j++; tmp_best++; }
        if (best < tmp_best) {
            s = candidate;
            best = tmp_best;
        }
        i = j - 1;
    }

    cout << s << ' ' << best << '\n';

    return 0;
}
