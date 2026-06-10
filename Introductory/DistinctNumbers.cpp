#include <algorithm>
#include <iostream>
#include <vector>
// #include <map>
// #include <set>

using namespace std;

/*
int main() {
  int n;
  cin >> n;
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    freq[m]++;
  }

  cout << freq.size();
}
*/

/*
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << s.size() << "\n";
}
*/

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  auto pos = unique(v.begin(), v.end());
  cout << pos - v.begin();
}
