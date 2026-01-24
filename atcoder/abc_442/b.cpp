#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int volume = 0, playing = 0;
    int q, a;
    cin >> q;

    while(q--) {
        cin >> a;
        if (a == 1) volume++;
        if (a == 2) volume = max(volume - 1, 0);
        if (a == 3) playing = !playing;

        if (volume >= 3 && playing) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }

    return 0;
}
