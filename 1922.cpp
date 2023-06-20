#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll binpow(ll a, ll b, ll m) {
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
  // even indices have 5 choices.
  // Odd indices have 4 choices.
  // Example:
  // n = 4
  // 5*4*5*4 => 5^2*4^2
  //
  // Edge case:
  // n = 5:
  //
  // 5*4*5*4*5 => 5^3 * 4 ^2
  ll n;
  ll m = 1000000007;
  ll res = 1;

  cin >> n;

  if (n > 1) {
    res = binpow(4, n / 2, m);
    n -= n / 2;
  }
  res = (res * binpow(5, n, m)) % m;

  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
