#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;

    ll n; cin >> n;
    vl arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    ll curr = 0;
    ll maxS = LLONG_MIN;

    for(int i = 0; i < n; i++){
        curr = max(arr[i], curr + arr[i]);
        maxS = max(maxS, curr);
    }

    cout << maxS;

    return 0;
}