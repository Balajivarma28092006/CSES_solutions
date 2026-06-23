#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> values(n + 1);
  int x, a, b, c;
  cin >> x >> a >> b >> c;

  values[0] = 0;
  values[1] = static_cast<long long>(x);
  for (int i = 2; i <= n; i++) {
    values[i] = static_cast<long long>((a * values[i - 1] + b) % c);
  }

  vector<long long> XORS;
  int left = 1;
  long long sum = 0;
  for (int right = 1; right <= n; right++) {
    sum += values[right];
    while (right - left + 1 > k) {
      sum -= values[left];
      left++;
    }

    if (right - left + 1 == k) {
      XORS.push_back(sum);
    }
  }

  long long final_xor = 0;
  for (auto &it : XORS) {
    final_xor ^= it;
  }

  cout << final_xor << "\n";
  return 0;
}
