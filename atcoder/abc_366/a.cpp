#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, t, a;
    cin >> n >> t >> a;
    
    if(min(t, a) + (n - t - a) > max(t, a)) cout << "No";
    else cout << "Yes";
    cout << '\n';

    return 0;
}
