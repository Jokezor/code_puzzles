#include <algorithm>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class UnionFind {
public:
  int size;
  vector<int> parent;
  vector<int> rank;

  void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
  }

  int find_set(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find_set(parent[v]);
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      if (rank[a] < rank[b]) {
        swap(a, b);
      }
      parent[b] = a;
      if (rank[a] == rank[b]) {
        rank[a]++;
      }
    }
  }

  bool is_connected(int a, int b) { return parent[a] == parent[b]; }
};

void dfs(int v, vector<vector<int>> graph, set<int> &visited) {
  visited.insert(v);
  for (int u : graph[v]) {
    if (visited.find(u) == visited.end()) {
      dfs(u, graph, visited);
    }
  }
}

bool areDisjoint(set<int> s1, set<int> s2) {
  for (int a : s1) {
    for (int b : s2) {
      if (a == b) {
        return false;
      }
    }
  }
  return true;
}

void solution() {
  int n, m;

  cin >> n >> m;

  vector<vector<int>> languages(m);
  vector<vector<int>> employees(n);

  // We have which languages can speak to each other.
  // But we should check by going through the people's languages.
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    vector<int> known_languages;
    while (k--) {
      int l;
      cin >> l;
      known_languages.push_back(l);
    }
    for (int source_language : known_languages) {
      for (int target_language : known_languages) {
        languages[source_language - 1].push_back(target_language - 1);
      }
    }
    // Add the employees languages
    employees[i] = known_languages;
  }

  vector<set<int>> language_sets(m);

  // Take the sets once.
  for (int l = 0; l < m; l++) {
    dfs(l, languages, language_sets[l]);
  }

  // So I have the languages connected.
  // Now take these and union find on them.

  // Add 1 for each empty set.
  // We should essentially count how many disjoint sets we have.
  // Feels like union find.
  // The answer is the number of disjoint sets -1 + the number of employees with
  // zero languages
  //
  int ans = 0;

  set<int> full_set;
  vector<int> v_intersection;

  for (int employee = 0; employee < n; employee++) {
    if (employees[employee].size() == 0) {
      ans++;
      continue;
    }
    // Get the set of nodes reachable by all languages known by employee
    set<int> employee_set;
    for (int language : employees[employee]) {
      // Suspected bottleneck.
      for (int l : language_sets[language - 1]) {
        employee_set.insert(l);
      }
    }
    if (full_set.size() == 0) {
      full_set = employee_set;
    } else if (areDisjoint(employee_set, full_set)) {
      for (int a : employee_set) {
        full_set.insert(a);
      }
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
