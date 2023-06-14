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
  ll n;
  cin >> n;

  ll res = 0;
  ll m = 1000000007;

  if (n >= 5) {
    // Edge case, if instead of taking a multiple of 3, we could take 4, that is
    // preferable.
    if (n % 3 == 1) {
      res = binpow(3, (n / 3 - 1), m);
      n = n - 3 * (n / 3 - 1);
    } else {
      res = binpow(3, n / 3, m);
      n %= 3;
    }
    if (n)
      res = res * n % m;
  } else {
    res = n;
  }
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
