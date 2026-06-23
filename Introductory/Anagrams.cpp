#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  unordered_map<string, vector<string>> anagrams;
  for (const auto &s : words) {
    string temp = s;
    sort(temp.begin(), temp.end());
    anagrams[temp].push_back(s);
  }

  vector<vector<string>> valid_anagrams;
  for (const auto &[_, word_list] : anagrams) {
    if (word_list.size() >= 2) {
      valid_anagrams.push_back(word_list);
    }
  }

  cout << valid_anagrams.size() << "\n";
  for (auto &group : valid_anagrams) {
    cout << group.size() << "\n";
    for (auto &value : group) {
      cout << value << "\n";
    }
  }
  return 0;
}
