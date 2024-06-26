#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();
  std::ifstream file("data.txt");
  std::string line;
  std::vector<std::vector<int>> triangle;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int num;
    std::vector<int> row;
    while (iss >> num) {
      row.push_back(num);
    }
    triangle.push_back(row);
  }

  vector<vector<int>> dp = triangle;

  int n = dp.size();

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < dp[i].size(); j++) {
      dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  int res = dp[0][0];

  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
