#include<iostream>

using namespace std;
#define ll long long
void count(ll a, ll b){
    if((a+b)%3==0 && a <= 2*b && b <= 2*a){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ll n;
    cin >>n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        count(a,b);
    }
    return 0;
}