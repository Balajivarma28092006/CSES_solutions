#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        vector<int> p1(n), p2(n);

        for (int i = 0; i < n; i++)
            p1[i] = i + 1;

        int ties = n - (a + b);

        int idx = 0;

        // Player1 wins
        for (int i = 0; i < a; i++) {
            p2[idx] = p1[idx] - 1;
            if (p2[idx] < 1) p2[idx] = n;
            idx++;
        }

        // Player2 wins
        for (int i = 0; i < b; i++) {
            p2[idx] = p1[idx] + 1;
            if (p2[idx] > n) p2[idx] = 1;
            idx++;
        }

        // ties
        for (int i = 0; i < ties; i++) {
            p2[idx] = p1[idx];
            idx++;
        }

        for (int x : p1) cout << x << " ";
        cout << "\n";

        for (int x : p2) cout << x << " ";
        cout << "\n";
    }
}