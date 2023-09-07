#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

// vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
vector<int> coins = {50, 100, 200};
int ans = 0;

int getCoinSum(int i, int k, int c) {
  cout << i << "\n";
  if (i < 0) {
    return 0;
  }

  if (c == 200) {
    ans += 1;
  }

  if (c > 200) {
    if (k * coins[i] > 200) {
      getCoinSum(i - 1, 0, 0);
    }
    getCoinSum(i - 1, 0, 0);
  } else {
    getCoinSum(i, k + 1, c + coins[i]);
  }

  return ans;
}

#define ll long long

int main() {

  clock_t start = clock();

  int i = coins.size() - 1;

  int c = 0;

  cout << getCoinSum(i, c) << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
