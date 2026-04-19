#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string p1, p2;
    cin >> p1 >> p2;
    string ans = "";

    if (p1 == "aristovaldo" && p2 == "fabiana") ans = "irmao";
    else if (p1 == "fabiana" && p2 == "aristovaldo") ans = "irma";
    else if (p1 == "aristovaldo" && p2 == "daniel") ans = "pai";
    else if (p1 == "daniel" && p2 == "aristovaldo") ans = "filho";
    else if (p1 == "aristovaldo" && p2 == "bruna") ans = "pai neto";
    else if (p1 == "bruna" && p2 == "aristovaldo") ans = "avo filha";
    else if (p1 == "aristovaldo" && p2 == "carlos") ans = "avo filho";
    else if (p1 == "carlos" && p2 == "aristovaldo") ans = "pai neto";
    else if (p1 == "fabiana" && p2 == "daniel") ans = "mae";
    else if (p1 == "daniel" && p2 == "fabiana") ans = "filho";
    else if (p1 == "fabiana" && p2 == "bruna") ans = "mae neta";
    else if (p1 == "bruna" && p2 == "fabiana") ans = "avo filha";
    else if (p1 == "fabiana" && p2 == "carlos") ans = "avo filha";
    else if (p1 == "carlos" && p2 == "fabiana") ans = "pai neto";
    else if (p1 == "daniel" && p2 == "bruna") ans = "irmao";
    else if (p1 == "bruna" && p2 == "daniel") ans = "irma";
    else if (p1 == "daniel" && p2 == "carlos") ans = "neto";
    else if (p1 == "carlos" && p2 == "daniel") ans = "avo";
    else if (p1 == "bruna" && p2 == "carlos") ans = "mae neta";
    else if (p1 == "carlos" && p2 == "bruna") ans = "avo filho";

    cout << ans << '\n';

    return 0;
}
