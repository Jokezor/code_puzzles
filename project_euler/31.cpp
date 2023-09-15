#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
map<int, int> sum_count;

void getCoinSum(int i) {

  map<int, int> new_sum_count;
  int k = 1;

  while (k * coins[i] < 200) {
    for (int j = 1; j < 200; j++) {
      if (j + k * coins[i] > 200) {
        break;
      }
      if (sum_count[j] > 0) {
        new_sum_count[j + k * coins[i]] += (sum_count[j]);
      }
    }
    k++;
  }

  k = 1;
  while (k * coins[i] <= 200) {
    new_sum_count[k * coins[i]]++;
    k++;
  }

  for (int p = 0; p <= 200; p++) {
    sum_count[p] += new_sum_count[p];
  }
}

#define ll long long

int main() {

  clock_t start = clock();

  for (int i = 0; i < coins.size(); i++) {
    getCoinSum(i);

    for (int j = 0; j <= 200; j++) {
      cout << j << ": " << sum_count[j] << "\n";
    }
  }
  cout << sum_count[200] << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
