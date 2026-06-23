#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back({x, i + 1});
  }

  sort(nums.begin(), nums.end());
  int left = 0, right = n - 1;
  while (left < right) {
    int sum = nums[left].first + nums[right].first;
    if (sum == k) {
      cout << nums[left].second << " " << nums[right].second;
      return 0;
    } else if (k < sum)
      right--;
    else
      left++;
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
