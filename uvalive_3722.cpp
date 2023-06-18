#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll binpow(ll a, ll b, ll m) {
  // Function for fast binary exponentiation
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solution() {
  // Read x, a, n, c for each test case
  ll x, a, n, c;

  while (cin >> x >> a >> n >> c) {
    if (x == 0) {
      break;
    }

    // Calculate total coins = x * a^n mod c using binary exponentiation
    ll total_coins = binpow(a, n, c) * x % c;

    // Calculate number of diamond rings bought = a^(n+1) mod [(a-1)*c] using
    // binary exponentiation
    ll rings_bought = binpow(a, n + 1, (a - 1) * c);

    // Calculate the remaining gold coins after buying rings and adjusting for
    // mod c
    cout << ((total_coins - (rings_bought - 1) / (a - 1) + 1 + c) % c) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
