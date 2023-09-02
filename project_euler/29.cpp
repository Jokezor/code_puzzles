#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

mpz_class get_power(mpz_class a, mpz_class b) {
  mpz_class res = 1;
  while (b) {
    res *= a;
    b--;
  }

  return res;
}

int main() {

  clock_t start = clock();

  int max_a = 100;
  int max_b = 100;
  int min_b = 2;

  set<mpz_class> distincts;

  // Now check how many numbers conflict with primes.
  for (mpz_class a = 2; a <= max_a; a++) {
    for (mpz_class b = 2; b <= max_b; b++) {
      distincts.insert(get_power(a, b));
    }
  }

  cout << distincts.size() << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
