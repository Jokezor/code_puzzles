#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int N;
  int mod = 998244353;

  cin >> N;

  int a[N][2];
  int dp[N][2];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &a[i][j]);
      dp[i][j] = 0;
    }
  }
  dp[0][0] = dp[0][1] = 1;
  for (int i = 1; i < N; i++) {
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        if (a[i - 1][x] != a[i][y]) {
          dp[i][y] += dp[i - 1][x];
        }
      }
    }
    dp[i][0] %= mod;
    dp[i][1] %= mod;
  }

  printf("%u\n", (dp[N - 1][0] + dp[N - 1][1]) % mod);
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
