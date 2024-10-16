#include <bits/stdc++.h>

typedef long long ll;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
const ll mod = 998244353, MAX = 300005, INF = 1 << 30;

using namespace std;

void solution() {
  int n;

  cin >> n;

  string s;

  vector<int> L(n);
  vector<int> R(n);
  vector<ll> dp(n);

  cin >> s;

  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
    dp[i] = INF;
  }
  dp[0] = 0;

  // Make a anonymous dfs
  auto dfs = [&](auto self, int v) -> void {
    if (L[v] != -1) {
      // Take the smallest out of dp at left
      // Or dp of current + switching the char to not be left?
      chmin(dp[L[v]], dp[v] + (s[v] != 'L'));
      // Perform DFS with left of current node
      self(self, L[v]);
    }
    if (R[v] != -1) {
      // If there is a right one, check if we need to swap right to reach
      // the right node
      chmin(dp[R[v]], dp[v] + (s[v] != 'R'));
      // Then dfs on right node.
      self(self, R[v]);
    }
  };

  dfs(dfs, 0);
  ll ans = INF;

  for (int i = 0; i < n; i++) {
    if (L[i] == -1 && R[i] == -1) {
      chmin(ans, dp[i]);
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
