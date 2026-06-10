#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(true);
    cin.tie();

    long long n;
    cin >> n;
    while(n!=1){
        if(n&1){
            cout << n << " \n";
            n = 3*n + 1;
        } else {
            cout << n << " \n";
            n /= 2;
        }
    }
    cout << n << " \n";
    return 0;
}