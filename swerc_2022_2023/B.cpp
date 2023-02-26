#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  // A simple solution is to start from the top.
  // Consider each level h-1.
  // Place the bricks where they are valid positions from the level above
  // While placed as close as possible.
  //
  // For level 0, no bricks are needed.
  // For level 1, the minimum required is n/2 if all bricks lie on a line
  //
  // Sort all bricks. Place the brick on the x_i + 1 position.
  // Check if there is a brick in [x_i - 1, x_i + 1] else, place the brick at
  // x_i + 1
  //
  // Actually, should place bricks closer to eachother.
  // So we will eventually build all the way down
  // But how to know if building closer is cheaper than building down?
  //
  // Take the minimum of connecting as many as possible
  //
  // Say we have the number of connecting two points.
  // To be honest.
  // I don't have any clear answer after looking at it for several hours.
  // I would need nlogn solution.
  // My guess is sorting + binary search on the brick positions
  int n, h;

  cin >> n >> h;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    dp[i][i] = h;
  }

  for (int l = 0; l < n; l++) {
    for (int r = l + 1; r < n; r++) {
      for (int m = l; m < r; m++) {
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] -
                                     max(0, h + 1 - (x[r] - x[l] + 1) / 2));
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
