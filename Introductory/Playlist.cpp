#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = 0;
  int left = 0;
  set<int> window;

  for (int right = 0; right < n; right++) {
    while (window.count(arr[right])) {
      window.erase(arr[left]);
      left++;
    }
    window.insert(arr[right]);
    ans = max(ans, right - left + 1);
  }
  cout << ans;
  return 0;
}
