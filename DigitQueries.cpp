/*
    12345678910111213141516171819202122232425...
    for we have like 9 one digits, 180 2 digits and etc..
    ex:
        15th place digits is 15 > 9 so it cannot be in ones then 15 - 9 = 6 
        basically 6th place digit after all single digits numbers.
        find after how many whole numbers using n-1/2 th after 10 or 3 based on the case
        and then we get the number.
        for the position do (n-1)% length.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

using ll = long long;
char getThePlace(ll n){
    ll digits = 1;
    ll start = 1;
    ll count = 9;

    // find the correct block
    while(n > digits * count){
        n -= digits * count;
        digits++;
        start *= 10;
        count *= 10;
    }

    // find the actual number
    ll number = start + (n-1) / digits;

    // convert to string
    string s = to_string(number);
    return s[(n-1) % digits];
}

int main() {
    fastio;

    ll n; cin >> n;
    while(n--){
        ll x; cin >> x;
        cout << getThePlace(x) << "\n";
    }
    return 0;
}
