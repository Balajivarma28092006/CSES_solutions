#include <iostream>
using namespace std;

void tower(int n, char from, char aux, char to){
    if(n==1){
        cout << from << " " << to << "\n";
        return;
    } else {
        tower(n-1, from, to, aux);
        cout << from << " " << to << "\n";
        tower(n-1, aux, from, to);
    }
}

int main() {
    int n;
    cin >> n;
    int moves = ( 1 << n ) - 1;
    cout << moves << "\n";
    tower(n, '1', '2', '3');
    return 0;
}
