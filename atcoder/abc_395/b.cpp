#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<vector<char>> grid;

void update_grid(int i, int j) {
    for(int k = i; k <= j; k++)
	for(int l = i; l <= j; l++)
	    grid[k][l] = i % 2 == 0 ? '.' : '#';
}

int main(void) {
    mainIO();
    int n, i = 1;
    cin >> n; 
    int j = n -i + 1;
    grid.resize(n + 1, vector<char>(n + 1, '#'));
    while(i <= j) {
	update_grid(i, j);
	i++;
	j--;
    }

    for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++)
	    cout << grid[i][j];
	cout << '\n';
    }

    return 0;
}
