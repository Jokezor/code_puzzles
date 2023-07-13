#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();

  int k;

  cin >> k;

  int max_k = pow(k, k);
  int min_prod = max_k;

  for (int i = 2; i < max_k; i++) {
    int sum = 0;
    int prod = 1;

    int m = i;

    while (m) {
    }

    break;

    if (prod == sum && prod < min_prod) {
      min_prod = prod;
    }
  }

  cout << "product: " << min_prod << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
