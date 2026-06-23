#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> movies;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    movies.push_back({start, end});
  }

  sort(movies.begin(), movies.end(),
       [](const auto &a, const auto &b) { return a.second < b.second; });
  int canWatch = 1;
  int firstMovieEndTime = movies[0].second;

  for (int i = 1; i < n; i++) {
    if (movies[i].first >= firstMovieEndTime) {
      canWatch++;
      firstMovieEndTime = movies[i].second;
    }
  }

  cout << canWatch << "\n";
  return 0;
}
