#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int>> tree(1000000);
vector<int> a(1000000);

void dfs(int root, int parent, int cats, ll m, int &ans) {

  if (cats > m) {
    return;
  }

  int ok = 1;

  for (int i = 0; i < tree[root].size(); i++) {
    int child = tree[root][i];

    // This means we are not a leaf.
    if (child != parent) {
      ok = 0;
      // cats * a[child] + a[child] is basically a way to keep the cats
      // since a[child] is 1/0.
      dfs(child, root, cats * a[child] + a[child], m, ans);
    }
  }

  ans += ok;
}

int solution() {
  ll n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }

  int ans = 0;

  // Start the DFS search from 1
  dfs(0, 0, a[0], m, ans);

  cout << ans << endl;
  return 0;
}

int main() {

  int t = 1;
  while (t--)
    solution();
}
