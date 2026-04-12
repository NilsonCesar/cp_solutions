#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    double s;
    cin >> s;
    double aumento;
    string aumento_s;

    if (s <= 400) {
        aumento = 0.15;
        aumento_s = "15";
    } else if (s <= 800) {
        aumento = 0.12;
        aumento_s = "12";
    } else if (s <= 1200) {
        aumento = 0.1;
        aumento_s = "10";
    } else if (s <= 2000) {
        aumento = 0.07;
        aumento_s = "7";
    } else {
        aumento = 0.04;
        aumento_s = "4";
    }

    cout << fixed << setprecision(2);
    cout << "Novo salario: " << s + s * aumento << '\n';
    cout << "Reajuste ganho: " << aumento * s << '\n';
    cout << "Em percentual: " << aumento_s << " %" << '\n';

    return 0;
}
