#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();

  // This at first looked like we should perform binary exponentiation
  // But it is rather looking at the most efficient way to break up a number
  int n = 201;
  vector<int> dp(n);

  for (int i = 0; i < n; i++) {
    dp[i] = 100000;
  }

  dp[0] = 0;
  dp[1] = 0;
  for (int k = 2; k <= n; k++) {
    int min_i = -1;
    for (int i = 1; i <= k / 2; i++) {
      if (2 * i == k) {
        //       cout << k << "\n";
        dp[k] = 1 + dp[i];
        min_i = i;
      } else if ((k - i) % i == 0) {
        dp[k] = min(dp[k], 1 + dp[k - i]);
        min_i = i;
      } else {
        if ((1 + dp[k - i] + dp[i]) <= dp[k]) {
          dp[k] = min(dp[k], 1 + dp[k - i] + dp[i]);
          min_i = i;
        }
      }
    }
    cout << k << ": " << min_i << " : " << dp[k] << "\n";
  }

  int res = 0;
  for (int m : dp) {
    res += m;
  }
  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
