#include <bits/stdc++.h>
using namespace std;

int h, m, n;
vector<pair<int, int>> W;
map<pair<int, pair<int, int>>, long long> knapsack;

long long knapsack_solution(int i, int x, int y) {
    auto it = knapsack.find({i, {x, y}});
    if(it != knapsack.end())
        return knapsack[{i, {x, y}}];

    if(x < 0 || y < 0) {
        return -1e9;
    }

    if(i == 0) return 0;
    
    knapsack[{i, {x, y}}] = max(knapsack_solution(i - 1, x, y), max(knapsack_solution(i - 1, x - W[i].first, y) + 1, knapsack_solution(i - 1, x, y - W[i].second) + 1));

    return knapsack[{i, {x, y}}];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> h >> m;
    W.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> W[i].first >> W[i].second;

    long long ans = knapsack_solution(n, h, m);

    cout << ans << '\n';

    return 0;
}