#include <iostream>
using namespace std;

int zeros(int n){
    if(n < 0)return -1;
    int count = 0;
    //continuosly divide the number by 5 and 5 powers
    for(int i = 5; n / i >= 1; i*=5){
        count += n / i;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << zeros(n);
}