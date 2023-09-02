#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

vector<ll> trial_division(ll n) {
  vector<ll> factorization;

  for (ll d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  if (n > 1) {
    factorization.push_back(n);
  }

  return factorization;
}

map<int, int> get_prime_factors(ll n) {
  vector<ll> factorization = trial_division(n);
  map<int, int> prime_factors;

  for (ll v : factorization) {
    prime_factors[v]++;
  }

  return prime_factors;
}

int main() {

  clock_t start = clock();

  // A bit too big to compute.
  // 99*99 = 9801 combinations
  //
  // So, only computing 100^100 is the issue.
  // We could rely on big integers to solve it or look at the math.
  //
  // computing.
  //
  // Instead, let's look at when the sequence have distinct terms.
  //
  // {4, 9, 16, 25}
  // {8, 27, 64, 125}
  // {16, 81, 256, 625}
  // {32, 243, 1024, 3125}
  //
  // repeats: {16} (2^4) = (2^2)^2 = (4^2)
  //
  // If we would increase b, then 2^b and 4^b would conflict a couple of times.
  //
  //
  // Add the combinations of all the primes.
  set<int> unique_primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  // Add all and then subtract those conflicting
  int max_a = 100;
  int max_b = 100;
  int min_b = 2;

  int distincts = (max_a - 1) * (max_b - 1);

  //
  // Now check how many numbers conflict with primes.
  for (int a = 2; a <= max_a; a++) {
    if (unique_primes.find(a) != unique_primes.end()) {
      continue;
    }

    map<int, int> prime_factors = get_prime_factors(a);

    if (prime_factors.size() == 1) {
      cout << a << "\n";
      distincts -= (max_b - min_b) / (prime_factors.begin())->second;
      continue;
    }

    int common_power = (prime_factors.begin())->second;
    bool has_common_power = true;

    for (auto f : prime_factors) {
      if (a == 91) {
        cout << f.first << "^" << f.second << "\n";
      }
      if (f.second != common_power || common_power % 2 != 0 ||
          common_power <= 1) {
        has_common_power = false;
      }
    }

    if (has_common_power) {
      cout << a << "\n";
      distincts -= (max_b - min_b) / common_power;
    }
  }

  cout << distincts << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
