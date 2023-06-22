#include <bits/stdc++.h>
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

  // Idea: Take the prime factorization of a number.
  // Then the sum of the divisors are given by (p_1^(e_1+1) -1)/(p_1 - 1)
  // Where p_1 is one of the prime numbers and e_1 is the number of times it
  // occurs.
  //
  // For the general sum we repeat the above for all primes and their powers.
  //
  // Example: 220 = 20*11 = 2*2*5*11 = 2^2 * 5^1 * 11^1 => d(220) = ((2^(3)
  // -1)/(2 -1)) * ((5^2 - 1)/(5-1)) * (11^2 - 1)/(11 - 1) - n = 7 * (24/4) *
  // (120/10) -220 = 7*6*12 - 220 = 504 - 220 = 284
  //
  // 284 = 2^2 * 71^1 => d(284) = 7 * (71^2 -1)/70 -284 = 7 * 5040/70 - 284 = 7
  // * 72 -284 = 220
  //

  ll max_n = 10000;
  ll amicable_numbers = 0;

  for (ll n = 2; n < max_n; n++) {
    ll divisor_sum = sum_of_divisors(n);
    if (divisor_sum < max_n && n != divisor_sum &&
        n == sum_of_divisors(divisor_sum)) {
      amicable_numbers += n;
      cout << n << ": " << divisor_sum << "\n";
    }
  }

  cout << amicable_numbers << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
