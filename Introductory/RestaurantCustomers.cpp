#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int count = 0;
    
    vector<pair<int, int>> slots;

    for(int i = 0; i < n; i++){
        int arrival, departure;
        cin >> arrival >> departure;
        slots.push_back({arrival, 1});
        slots.push_back({departure, -1});
    }

    sort(slots.begin(), slots.end());

    int current = 0;
    int max_customers = 0;

    for(auto e: slots){
        current += e.second;
        max_customers = max(max_customers, current);
    }

    cout << max_customers;
    return 0;
}
