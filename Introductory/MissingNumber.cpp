#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long expected =   1LL * n * (n + 1) / 2;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        long long a;
        cin >> a;
        sum += a;
    }

    cout << expected - sum << "\n";
    return 0;
}