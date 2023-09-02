#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

// sieve of erastothenes
vector<bool> isPrime(int n) {
  vector<bool> is_prime(n + 1, true);

  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (ll)i * i <= n) {
      for (ll j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
};

vector<ll> sieve_of_eratosthenes(ll n) {
  vector<ll> primes;
  vector<ll> isPrime(n + 1, true);

  isPrime[0] = isPrime[1] = false;

  for (ll i = 2; i <= n; i++) {
    if (isPrime[i] && i * i <= n) {
      for (ll j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (ll i = 0; i < n + 1; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {

  clock_t start = clock();

  // Maximum number of primes for consecutive values of n
  // For n^2 + a*n + b
  // Since n=0 needs to be prime, then b needs to be prime.
  // Thus b can be any prime less than 1000.
  //
  // We can simply generate all primes < 1000*1000 + 1000*1000 + 1000 = 2*10^6 +
  // 1000
  //
  // We should return the product of the coefficients a and b.
  //
  // Then it would O(n * 2000 * 2*number_of_primes_less_than_1000)
  // If we say that there should be around 100, we get 400 * 10^3 * n
  // Which should be for n ~ 1000 max around 10^9 combinations to search.
  vector<ll> primes = sieve_of_eratosthenes(1000);
  vector<bool> is_prime = isPrime(2 * 1000000 + 1000);

  cout << "YES"
       << "\n";

  int N = 1000;
  int maxPrimes = 0;
  int best_b = 0;
  int best_a = 0;

  for (int a = -1000; a <= 1000; a++) {
    for (ll b : primes) {
      int n = 0;
      for (; n <= N; n++) {
        ll primeCandidate = n * n + a * n + b;

        if (primeCandidate <= 0) {
          break;
        }
        if (!is_prime[primeCandidate]) {
          break;
        }
      }
      if (n > maxPrimes) {
        maxPrimes = n;
        best_b = b;
        best_a = a;
      }
      n = 0;
      for (; n <= N; n++) {
        ll primeCandidate = n * n + a * n - b;

        if (primeCandidate <= 0) {
          break;
        }
        if (!is_prime[primeCandidate]) {
          break;
        }
      }
      if (n > maxPrimes) {
        maxPrimes = n;
        best_b = b;
        best_a = a;
      }
    }
  }

  cout << maxPrimes << best_b * best_a << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
