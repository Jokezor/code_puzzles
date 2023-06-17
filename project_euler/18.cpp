#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();
  vector<vector<int>> triangle = {
      {75},
      {95, 64},
      {17, 47, 82},
      {18, 35, 87, 10},
      {20, 4, 82, 47, 65},
      {19, 1, 23, 75, 3, 34},
      {88, 2, 77, 73, 7, 63, 67},
      {99, 65, 4, 28, 6, 16, 70, 92},
      {41, 41, 26, 56, 83, 40, 80, 70, 33},
      {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
      {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
      {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
      {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
      {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
      {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};

  vector<vector<int>> example_triangle = {{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};

  vector<vector<int>> dp = triangle;

  int n = dp.size();

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < dp[i].size(); j++) {
      dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  int res = dp[0][0];

  cout << res << "\n";

  dp = triangle;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (j == 0) {
        dp[i][j] += dp[i - 1][j];
      } else if (j == dp[i].size() - 1) {
        dp[i][j] += dp[i - 1][j - 1];
      } else {
        dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
  }

  res = 0;
  for (int j = 0; j < n; j++) {
    res = max(res, dp[n - 1][j]);
  }

  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
