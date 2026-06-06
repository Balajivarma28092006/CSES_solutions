#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        tickets.insert(t);
    }

    for(int i = 0; i < m ; i++){
        int p; cin >> p;
        auto it = tickets.upper_bound(p);
        if(it == tickets.begin()){
            cout << -1 << "\n";
        }else{
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}