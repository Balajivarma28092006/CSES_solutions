#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

ll countBits(ll n) {
    ll total_set_bits = 0;
    ll i = 0;

    while((1LL << i) <= n) {
        ll cycle_length = 1LL << (i + 1);
        ll full_cycles = (n + 1) / cycle_length;

        total_set_bits += full_cycles * (1LL << i);

        ll remainder = (n + 1) % cycle_length;
        if(remainder > (1LL << i)) {
            total_set_bits += (remainder - (1LL << i));
        }
        i++;
    }
    return total_set_bits;
}

int main() {
    fastio;

    ll n;
    cin >> n;
    cout << countBits(n);

    return 0;
}