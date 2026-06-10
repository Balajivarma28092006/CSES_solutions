#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

vector<int> generate(int n) {
  vector<int> result;
  int total = 1 << n;
  for (int i = 0; i < total; i++) {
    int t = i ^ (i >> 1);
    result.push_back(t);
  }
  return result;
}

int main() {
  int n;
  if (!(cin >> n))
    return 0;
  auto binaries = generate(n);
  for (int code : binaries) {
    string s = bitset<32>(code).to_string();
    cout << s.substr(32 - n) << endl;
  }
  return 0;
}
