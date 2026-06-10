#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;

     int n;
    cin >> n;

    vector<int> rows(n), cols(n);

    for (int &x : rows) cin >> x;
    for (int &x : cols) cin >> x;

    int sr = accumulate(rows.begin(), rows.end(), 0);
    int sc = accumulate(cols.begin(), cols.end(), 0);

    if (sr != sc) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> grid(n, vector<int>(n, 0));
    priority_queue<pair<int, int>> pq;

    return 0;
}