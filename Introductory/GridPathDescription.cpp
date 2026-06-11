#include <bits/stdc++.h>

using namespace std;

// all the global guys
string s;
bool vis[7][7];
int ans = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};


bool inside(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7;
}

void dfs(int r, int c, int idx) {
    if (r == 6 && c == 0) {
        if (idx == 48) ans++;
        return;
    }

    if (idx == 48) return;

     // corridor pruning
    if ((r == 0 || vis[r - 1][c]) &&
        (r == 6 || vis[r + 1][c]) &&
        c > 0 && !vis[r][c - 1] &&
        c < 6 && !vis[r][c + 1])
        return;

    if ((c == 0 || vis[r][c - 1]) &&
        (c == 6 || vis[r][c + 1]) &&
        r > 0 && !vis[r - 1][c] &&
        r < 6 && !vis[r + 1][c])
        return;

    vis[r][c] = true;
    char cc = s[idx];

    for(int k = 0; k < 4; k++) {
        if( cc != '?' && dir[k] != cc) continue;

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (!inside(nr, nc) || vis[nr][nc]) continue;
        dfs(nr, nc, idx + 1);
    }
    vis[r][c] = false;
}

int main() {
    cin >> s;
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}