#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

bool makePalindrome(std::string &s) {
  std::unordered_map<char, int> freq;
  for (char c : s)
    freq[c]++;

  int oddCount = 0;
  char middle = '\0';

  for (auto &p : freq) {
    if (p.second % 2 != 0) {
      oddCount++;
      middle = p.first;
    }
  }

  if (oddCount > 1) {
    return false;
  }

  std::string left;
  for (auto &p : freq) {
    left.append(p.second / 2, p.first);
  }

  std::string right = left;
  std::reverse(right.begin(), right.end());

  s = left;
  if (oddCount == 1) {
    s += middle;
  }
  s += right;
  return true;
}

int main() {
  std::string input;
  std::cin >> input;
  if (makePalindrome(input)) {
    std::cout << input << "\n";
  } else {
    std::cout << "NO SOLUTIONS\n";
  }
}
