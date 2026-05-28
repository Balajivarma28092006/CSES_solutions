#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define all(x) (x).begin(), (x).end()

/*
    so basically the significance of a, b is they should win that many times

*/

void solve(int n, int a, int b) {
    if (a + b > n) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    int draws = n - (a+b);

    vector<int> p1, p2;
    for(int i = 0; i < draws; i++){
        p1.push_back(i);
        p2.push_back(i);
    }

    vector<int> rem;
    for(int i = draws+1; i <= n; i++){
        rem.push_back(i);
    }

    int left = 0, right = rem.size() - 1;
    // p1 wins
    for(int i = 0; i < a; i++){
        p1.push_back(rem[right--]);
        p2.push_back(rem[left++]);
    }

    //p2 wins
    for(int i = 0; i < b; i++) {
        p1.push_back(rem[left++]);
        p2.push_back(rem[right--]);
    }

    for(int a: p1) cout << a << " ";
    cout << "\n";
    for(int a: p2) cout << a << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }    

    return 0;
}