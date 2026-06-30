#include <bits/stdc++.h>
#include <climits>

#include <functional>
#include <ios>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> neighbours(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    neighbours[a - 1].push_back({b - 1, c}); // node --> distance
  }

  vector<long long> dist(n, LLONG_MAX);
  using T = pair<long long, int>;
  priority_queue<T, vector<T>, greater<T>> pq;

  int start = 0;
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    const auto [len, to] = pq.top();
    pq.pop();
    if (len > dist[to])
      continue;

    for (const pair<int, int> &it : neighbours[to]) {
      if (len + it.second < dist[it.first]) {
        dist[it.first] = len + it.second;
        pq.push({dist[it.first], it.first});
      }
    }
  }

  for (auto &d : dist)
    cout << d << " ";
  return 0;
}
