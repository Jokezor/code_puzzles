#include <fstream>
#include <gmpxx.h>
#include <sstream>
#include <string>
#include <vector>

#include <bits/stdc++.h>
#include <time.h>

#define ll unsigned long long

using namespace std;

int main() {
  // Essentially, this algorithm works but only for smaller n.
  // Since n is actually unbounded, we need to think of ways of doing
  // such a comparison with array operations.

  clock_t start = clock();

  mpz_class D = 61;
  mpz_class n = 226153980;
  mpz_class max_X = 0;
  mpz_class optimal_D = 0;

  for (mpz_class d = 2; d <= D; d++) {
    mpz_class min_X = 0;
    for (mpz_class y = 1; y <= n; y++) {
      mpz_class x_candidate = (mpz_class(1) + d * y * y);
      mpz_class sqrt_x_candidate = mpz_class(sqrt(x_candidate));
      if (d == 61 && y % 1000 == 0) {
        cout << sqrt_x_candidate << " " << x_candidate << "\n";
      }
      if ((sqrt_x_candidate * sqrt_x_candidate) == x_candidate) {
        if (min_X == 0) {
          min_X = sqrt_x_candidate;
        }
        min_X = min(min_X, sqrt_x_candidate);
      }
    }
    cout << min_X << "\n";
    if (min_X > max_X) {
      max_X = min_X;
      optimal_D = d;
    }
  }

  cout << "x=" << max_X << " occured for d=" << optimal_D << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
