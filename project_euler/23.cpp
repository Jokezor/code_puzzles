#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

vector<ll> trial_division1(ll n) {
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

ll sum_prime_power(int prime, int power) {
  return (pow(prime, power + 1) - 1) / (prime - 1);
}

ll sum_of_divisors(ll n) {
  vector<ll> factorization = trial_division1(n);
  map<int, int> prime_factors;

  for (ll v : factorization) {
    prime_factors[v]++;
  }

  ll res = 1;

  for (pair factor : prime_factors) {
    res *= sum_prime_power(factor.first, factor.second);
  }

  res -= n;

  return res;
}

int main() {

  clock_t start = clock();

  vector<int> abundant_numbers;
  bool sum_of_abundants[28123 * 2 + 1] = {false};

  // Generate all abundant numbers
  ll max_n = 28123;

  for (ll n = 12; n <= max_n; n++) {
    ll divisor_sum = sum_of_divisors(n);
    if (divisor_sum > n) {
      abundant_numbers.push_back(n);
      cout << n << ": " << divisor_sum << "\n";
    }
  }

  // Add all the sums
  for (int i = 0; i < abundant_numbers.size(); i++) {
    for (int j = 0; j <= i; j++) {
      sum_of_abundants[abundant_numbers[i] + abundant_numbers[j]] = true;
    }
  }

  // sum all numbers not in the set
  ll res = 0;
  for (int i = 1; i <= max_n; i++) {
    if (!sum_of_abundants[i]) {
      res += i;
    }
  }

  //
  // Add the sum of all abundant numbers seen to the abundant_number_sums set
  // upon discovering a new one.

  // Go through all numbers from 1 to 28123 and if not present in
  // abundant_number_sums, then add it to res.

  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
