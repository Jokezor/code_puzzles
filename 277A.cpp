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
  int n, m;

  int ans = 0;

  cin >> n >> m;

  vector<vector<int>> employees(n);

  // Use union find to get disjoint sets.
  UnionFind uf;

  uf.size = m;
  uf.parent = vector<int>(m);
  uf.rank = vector<int>(m);

  for (int i = 0; i < m; i++) {
    uf.make_set(i);
  }

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
        uf.union_sets(source_language, target_language);
      }
    }
    // Add the employees languages
    employees[i] = known_languages;
  }

  // Now lets check which are connected.
  // Actually, we should not always start with employee 0.
  // What if that employee only knows one language?
  // Would be better to start with the employees that knows the most languages!

  vector<pair<int, int>> cultural_employees(n);

  for (int i = 0; i < n; i++) {
    cultural_employees[i] = make_pair((int)employees[i].size(), i);
  }

  // Ensure the employees which knows the most languages goes first.
  sort(cultural_employees.begin(), cultural_employees.end(),
       [&](pair<int, int> p1, pair<int, int> p2) {
         return p1.first > p2.first;
       });

  for (int i = 0; i < n; i++) {
    int e1 = cultural_employees[i].second;
    if (employees[e1].size() == 0) {
      ans++;
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      int e2 = cultural_employees[j].second;

      vector<int> e1_languages = employees[e1];
      vector<int> e2_languages = employees[e2];

      bool connected = false;

      for (int l1 : e1_languages) {
        for (int l2 : e2_languages) {
          if (uf.is_connected(l1, l2)) {
            connected = true;
          }
        }
      }
      if (!connected) {
        for (int l1 : e1_languages) {
          for (int l2 : e2_languages) {
            uf.union_sets(l1, l2);
          }
        }
        for (int l2 : e2_languages) {
          employees[e1].push_back(l2);
        }
        for (int l1 : e1_languages) {
          employees[e2].push_back(l1);
        }
        ans++;
      }
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
