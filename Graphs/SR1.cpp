#include <climits>

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    graph[u][v] = w;
    graph[v][u] = w;
  }

  vector<long long> dist(n, LLONG_MAX);
  vector<bool> seen(n, false);
  int src = 0;
  dist[src] = 0;

  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++) {
      if (!seen[j] && (u == -1 || dist[u] > dist[j])) {
        u = j;
      }
    }
    if (u == -1 || dist[u] == LLONG_MAX)
      break;
    seen[u] = true;
    for (int v = 0; v < n; v++) {
      if (graph[u][v] != 0) {
        int wt = graph[u][v];
        if (dist[v] > dist[u] + wt) {
          dist[v] = dist[u] + wt;
        }
      }
    }
  }

  for (auto &c : dist)
    cout << c << " ";
  return 0;
}
