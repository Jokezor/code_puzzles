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

void solution() {
  int n, m, ans;

  cin >> n >> m;

  vector<vector<int>> languages(m);
  vector<vector<int>> employees(n);

  // Union find the language sets.

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    vector<int> known_languages;
    while (k--) {
      int l;
      cin >> l;
      known_languages.push_back(l - 1);
    }
    for (int source_language : known_languages) {
      for (int target_language : known_languages) {
        languages[source_language].push_back(target_language);
      }
    }
    // Add the employees languages
    employees[i] = known_languages;
  }

  // Use union find to get disjoint sets.
  UnionFind uf;

  uf.size = m;
  uf.parent = vector<int>(m);
  uf.rank = vector<int>(m);

  for (int i = 0; i < m; i++) {
    uf.make_set(i);
  }

  for (int i = 0; i < m; i++) {
    for (int l : languages[i]) {
      uf.union_sets(i, l);
    }
  }

  // Now lets check which are connected.
  //
  for (int e1 = 0; e1 < n; e1++) {
    if (employees[e1].size() == 0) {
      ans++;
      continue;
    }
    bool connected = false;
    int source_language;
    int target_language;

    for (int e2 = e1 + 1; e2 < n; e2++) {
      vector<int> e1_languages = employees[e1];
      vector<int> e2_languages = employees[e2];

      for (int l1 : e1_languages) {
        for (int l2 : e2_languages) {
          if (uf.is_connected(l1, l2)) {
            connected = true;
          }
        }
      }

      if (!connected) {
        if (e1_languages.size() != 0 && e2_languages.size() != 0) {
          source_language = e1_languages[0];
          target_language = e2_languages[0];
        }
      }
    }
    if (!connected) {
      ans++;
      uf.union_sets(source_language, target_language);
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
