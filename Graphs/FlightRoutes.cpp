#include <climits>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<long long> max_heights(int src,
                              vector<vector<pair<int, int>>> &neighbours) {
  vector<long long> max_costs(neighbours.size(), LLONG_MAX);
  max_costs[src] = 0;

  using T = pair<long long, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    T costs = pq.top();
    pq.pop();
    if (costs.first > max_costs[costs.second])
      continue;

    for (const T &it : neighbours[costs.second]) {
      long long new_cost = it.second + max_costs[costs.second];
      if (new_cost < max_costs[it.first]) {
        max_costs[it.first] = new_cost;
        pq.push({max_costs[it.first], it.first});
      }
    }
  }
  return max_costs;
}

int main() {
  int city_count, flight_count;
  cin >> city_count >> flight_count;

  vector<vector<pair<int, int>>> neighbours(city_count);
  vector<vector<pair<int, int>>> reverse_neighbours(city_count);

  for (int i = 0; i < flight_count; i++) {
    int from, to, len;
    cin >> from >> to >> len;
    from--;
    to--;
    neighbours[from].push_back({to, len});
    reverse_neighbours[to].push_back({from, len});
  }
  vector<long long> start_costs = max_heights(0, neighbours);
  vector<long long> end_costs = max_heights(city_count - 1, reverse_neighbours);

  long long ans = LLONG_MAX;
  for (int i = 0; i < city_count; i++) {
    for (auto [n, nc] : neighbours[i]) {
      if (start_costs[i] == LLONG_MAX || end_costs[n] == LLONG_MAX)
        continue;
      ans = min(ans, start_costs[i] + (nc / 2) + end_costs[n]);
    }
  }

  cout << ans << "\n";
  return 0;
}
