#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main(){
    fastio;

    /*
     * find the gondola and it can only have 1 or 2 childern
     * the total weight will not exceed x.
     */

    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());
    int count = 0;

    /*
     * lets go with the two pointer approach
     * add the light and heavy one if its less than or equal give for one gondola
     * else give the heaviest guy to it
     */

    int i = 0;
    int j = n - 1;

    while(i <= j){
        if(weights[i] + weights[j] <= x){
            i++; j--;
        }else{
            j--;
        }
        count++;
    }

    cout << count;
    return 0;
}
