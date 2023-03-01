#include <bits/stdc++.h>

#define ll long long

using namespace std;

int bfs(vector<vector<pair<int, int>>> tree, pair<int, int> r, int m) {

  set<int> visited;
  int ans = 0;
  deque<tuple<int, int, int>> q;

  // Add to the queue
  q.push_back({r.first, r.second, r.second});

  // Pop it like its hot
  while (!q.empty()) {
    tuple<int, int, int> root = q.front();
    q.pop_front();

    visited.insert(get<0>(root));

    if (tree[get<0>(root)].size() <= 1 && get<0>(root) != 1) {
      if (get<2>(root) <= m && get<1>(root) <= m) {
        ans++;
      }
    } else {
      for (auto child : tree[get<0>(root)]) {
        if (visited.find(child.first) == visited.end()) {
          visited.insert(child.first);
          // Max consecutive in 3rd
          // Current consecutive in 2nd
          if (child.second) {
            q.push_back({child.first, get<1>(root) + child.second,
                         max(get<2>(root), get<1>(root) + child.second)});
          } else {
            q.push_back({child.first, 0, get<2>(root)});
          }
        }
      }
    }
  }

  return ans;
}

int solution() {
  int n, m;

  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Build the tree
  vector<vector<pair<int, int>>> T(n + 1);

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    T[y].push_back({x, a[i]});
    T[x].push_back({y, a[i]});
  }

  // Start the BFS search from 1
  int ans = bfs(T, {1, a[0]}, m);

  cout << ans << endl;

  // Does not care if the restaurant contains a cat or not.
  // Just the path to it.
  // If there is a cat in his house, this counts as 1.
  // Simply build up a graph and add the cats seen.
  // Run DFS and count the pairs.

  return 0;
}

int main() {

  int t = 1;
  while (t--)
    solution();
}
