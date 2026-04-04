#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    map<int, map<int, int>> gothec;
    gothec[1][7] = 1;
    gothec[3][3] = 1;
    gothec[5][5] = 1;
    gothec[7][7] = 1;
    gothec[9][9] = 1;

    int m, d;
    cin >> m >> d;
    if (gothec[m][d]) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}
