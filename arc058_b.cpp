#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int modN = 1000000007;
  // What should we do?
  int H, W, A, B;

  cin >> H >> W >> A >> B;

  vector<vector<int>> dp(H);

  for (int i = 0; i < H; i++) {
    dp[i] = vector<int>(W);
    dp[i][0] = 1;
  }

  for (int j = 0; j < W; j++) {
    dp[0][j] = 1;
  }

  for (int i = H - 1; i >= H - A; i--) {
    for (int j = 0; j < B; j++) {
      dp[i][j] = 0;
    }
  }

  auto factorial = [&](int m) {
    ll res = 1;
    for (int i = 1; i <= m; i++) {
      res = (res % modN) * (i % modN) % modN;
    }
    return res % modN;
  };

  // cout << factorial(W - 1) << endl;
  cout << factorial(H + W - 2) << "\n";
  cout << factorial(H - 1) << "\n";
  cout << factorial(W - 1) << "\n";

  ll all_combinations = (((factorial(H + W - 2) % modN)) /
                         ((factorial(H - 1) * factorial(W - 1)) % modN));
  ll combinations_removed =
      (((factorial(A - 1) % modN) * (factorial(B - 1) % modN)) /
       ((factorial(A - 1)) % modN));

  cout << all_combinations << "\n";

  /*
  for (int i = 1; i < H; i++) {
    for (int j = 1; j < W; j++) {
      if (i >= (H - A) && j < B) {
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  cout << dp[H - 1][W - 1] % modN << "\n";
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
