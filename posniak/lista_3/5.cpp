#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int d, m;
    cin >> d >> m;

    switch (m)
    {
    case 1:
        if (d <= 19) cout << "capricornio";
        else cout << "aquario";
        break;
    case 2:
        if (d <= 18) cout << "aquario";
        else cout << "peixes";
        break;
    case 3:
        if (d <= 20) cout << "peixes";
        else cout << "aries";
        break;
    case 4:
        if (d <= 20) cout << "aries";
        else cout << "touro";
        break;
    case 5:
        if (d <= 20) cout << "touro";
        else cout << "gemeos";
        break;
    case 6:
        if (d <= 20) cout << "gemeos";
        else cout << "cancer";
        break;
    case 7:
        if (d <= 22) cout << "cancer";
        else cout << "leao";
        break;
    case 8:
        if (d <= 22) cout << "leao";
        else cout << "virgem";
        break;
    case 9:
        if (d <= 22) cout << "virgem";
        else cout << "libra";
        break;
    case 10:
        if (d <= 22) cout << "libra";
        else cout << "escorpiao";
        break;
    case 11:
        if (d <= 21) cout << "escorpiao";
        else cout << "sagitario";
        break;
    case 12:
        if (d <= 21) cout << "sagitario";
        else cout << "capricornio";
        break;
    default:
        break;
    }
    cout << '\n';

    return 0;
}
