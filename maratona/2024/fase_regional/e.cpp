#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate_counterclockwise(vector<vector<int>> a, int n) {
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][i] = a[i][n - j - 1];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << b[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return b;
}

bool valid(vector<vector<int>> a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j + 1] < a[i][j]) {
                return false;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1][j] < a[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b = rotate_counterclockwise(a, n);

    int r = 0;

    while(!valid(a, n)) {
        a = rotate_counterclockwise(a, n);
        r++;

        // cout << "round: " << r << '\n';
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << r << '\n';

    return 0;
}