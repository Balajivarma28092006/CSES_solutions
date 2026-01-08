#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string given;
    cin >> given;
    long long max_len = 1;
    long long current_len = 1;

    for(int i = 1; i < given.size(); i++){
        if(given[i] == given[i-1]){
            current_len++;
        } else {
            current_len = 1;
        }
        max_len = max(max_len, current_len);
    }
   
    
    cout << max_len << "\n";
    return 0;
}