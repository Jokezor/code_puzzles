#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> h(n + 10);
  vector<int> b(m + 10, 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    h[u].push_back({v, i});
    h[v].push_back({u, i});
  }
  int x = 1;
  for (; x <= n; x++) {
    if ((int)h[x].size() < n - 1) {
      break;
    }
  }
  int sum = 0;
  if (x > n) {
    for (auto t : h[n]) {
      b[t.second] = 2;
    }
    b[h[n].back().second] = 3;
    sum = 3;
  } else {
    for (auto t : h[x]) {
      b[t.second] = 2;
    }
    sum = 2;
  }
  cout << sum << endl;
  for (int i = 1; i <= m; i++)
    cout << b[i] << ' ';
  cout << endl;
}

int main() {
  int V;
  scanf("%d", &V);
  while (V--) {
    solve();
  }
  return 0;
}
