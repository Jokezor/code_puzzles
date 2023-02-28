#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool sortpair(const tuple<int, int, int> &p1, const tuple<int, int, int> &p2) {
  if (get<0>(p1) == 0 || get<0>(p2) == 0 || get<1>(p1) == 0 ||
      get<1>(p2) == 0) {
    return false;
  }
  if (get<0>(p1) < get<0>(p2)) {
    return true;
    // return (get<0>(p1) < get<1>(p2));
  } else {
    return false;
    // return (get<0>(p2) < get<1>(p1));
  }
}

int dfs(vector<vector<pair<int, int>>> tree, set<int> &visited,
        pair<int, int> root, int cats, int maxCats, int m) {

  int ans = 0;

  // Take the first element
  // Increment ans if we reach a leaf with not cats reached m
  if (maxCats > m) {
    return ans;
  }

  // This is a leaf, increment ans.
  for (auto child : tree[root.first]) {
    if (visited.find(child.first) == visited.end()) {
      visited.insert(child.first);
      int new_ans = 0;
      cout << child.first << endl;
      // Only count consecutive cats.
      // If there is a cat, then increase.
      if (child.second) {
        new_ans = dfs(tree, visited, child, cats + child.second,
                      max(maxCats, cats + child.second), m);
      } else {
        new_ans = dfs(tree, visited, child, 0, maxCats, m);
      }
      ans += new_ans;
    }
  }

  cout << root.first << ":" << maxCats << endl;

  // This does not work if adding the path from both directions.
  if (tree[root.first].empty()) {
    if (maxCats <= m) {
      return 1;
    } else {
      return 0;
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
  // First sort both and take the smallest to the biggest.
  vector<tuple<int, int, int>> xy(2 * n - 2);

  vector<vector<pair<int, int>>> T(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    tuple<int, int, int> element = {x, y, a[i + 1]};
    xy[i] = element;

    tuple<int, int, int> reverse_element = {y, x, a[i + 1]};
    xy[i + n - 1] = reverse_element;
  }

  sort(xy.begin(), xy.end(), sortpair);

  set<int> pushed;

  for (int i = 0; i < 2 * n - 1; i++) {
    tuple<int, int, int> element = xy[i];
    if (get<0>(element) != 0 && pushed.find(get<0>(element)) == pushed.end() &&
        pushed.find(get<1>(element)) == pushed.end()) {
      T[min(get<0>(element), get<1>(element))].push_back(
          {max(get<0>(element), get<1>(element)), get<2>(element)});
    }
    cout << get<0>(element) << get<1>(element) << get<2>(element) << endl;
  }
  cout << "boo" << endl;

  /*
  for (int i = 0; i < n; i++) {
    cout << "children for: " << i << endl;
    for (auto t : T[i]) {
      cout << t.first << " ";
    }
    cout << endl;
  }
  */

  set<int> visited;

  // Start the DFS search from 1
  int ans = dfs(T, visited, {1, a[0]}, a[0], a[0], m);

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
