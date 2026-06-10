#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
 
int main(){
	fio;
	int n;
    cin >> n;

    for(ll i = 1; i <= n; i++){
        ll total = i*i*(i*i-1)/2;// select two places to keep ways. 
        ll canAttact = 4*(i-1)*(i-2);
        cout << total - canAttact << "\n";
    }
	return 0;
}
 
