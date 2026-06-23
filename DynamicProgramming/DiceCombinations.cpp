#include <ios>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> dp(n + 1, 0);

  // so a die has 6 faces from 1 to 6
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int die = 1; die <= 6; die++) {
      if (i - die >= 0) {
        dp[i] = (dp[i] + dp[i - die]) % MOD;
      }
    }
  }

  cout << dp[n];
  return 0;
}
