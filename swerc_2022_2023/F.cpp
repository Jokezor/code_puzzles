#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  // Think about connected graphs and colouring
  // Need to construct the graph and check if its connected or not.
  int n, m;
  cin >> n >> m;

  // Construct the graph.
  // Vector of vector of pairs.
  vector<vector<pair<int, int>>> cities(n + 1);
  // Denote which company owns what route
  vector<int> owns_route(m + 1, 1);

  // Scan in all routes
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    cities[a].push_back({b, i});
    cities[b].push_back({a, i});
  }

  // Now check for a city that is not fully connected.
  int v = 1;
  for (; v <= n; v++) {
    if ((int)cities[v].size() < n - 1) {
      break;
    }
  }

  // Now we can check if v > n. Then we have a fully connected graph and need to
  // assign 3 colours. Else we assign 2 colours.
  int sum = 0;
  if (v > n) {
    for (auto p : cities[n]) {
      owns_route[p.second] = 2;
    }
    owns_route[cities[n].back().second] = 3;
    sum = 3;
  } else {
    for (auto p : cities[v]) {
      owns_route[p.second] = 2;
    }
    sum = 2;
  }

  cout << sum << endl;
  for (int i = 1; i <= m; i++) {
    cout << owns_route[i] << " ";
  }
  cout << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
