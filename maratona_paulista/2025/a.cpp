#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w, a, b, c;
    cin >> w >> a >> b >> c;
    cout << (w >= a + b + c ? 'S' : 'N') << '\n';
    
    return 0;
}