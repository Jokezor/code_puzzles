#include <bits/stdc++.h>

using namespace std;

#define ll long long

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

map<ll, ll> prime_factorization(ll n, vector<ll> primes) {
  map<ll, ll> factorization;
  for (ll d : primes) {
    if (d * d > n) {
      break;
    }
    while (n % d == 0) {
      factorization[d]++;
      n /= d;
    }
  }
  if (n > 1) {
    factorization[n]++;
  }

  return factorization;
}

int main() {

  // Precompute primes
  vector<ll> primes = sieve_of_eratosthenes(10000000);

  time_t timer;
  time_t start = time(&timer);

  ll n = 0;
  int divisors = 0;
  for (ll i = 1; i <= 100000; i++) {
    n += i;
    map<ll, ll> prime_factors = prime_factorization(n, primes);

    int current_divisors = 1;
    for (auto p : prime_factors) {
      current_divisors *= (p.second + 1);
    }
    divisors = max(divisors, current_divisors);
    if (divisors > 500) {
      break;
    }
  }

  cout << divisors << "\n";
  cout << n << "\n";

  time_t end = time(&timer);

  printf("took %.f seconds\n", difftime(end, start));

  return 0;
}
