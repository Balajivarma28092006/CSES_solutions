#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define ll long long

ll countNumberOfOnes(ll n) {
  ll count = 0;
  while(n > 0){
    n &= (n-1);
    count++;
  }
  return count;
}

int main() {
    fastio;

    int n; cin >> n;
    int ans = 0;
    for(ll i = 1; i <= n; i++){
      ans += countNumberOfOnes(i);
    }
    cout << ans;

    return 0;
}