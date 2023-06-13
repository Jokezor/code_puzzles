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
  // Always take the lowest multiple possible unless
  // After taking the multiple, the rest is < 2.
  // So take 2's and then the rest.
  // 5, take 2, 3, take 3.
  // binpow(4, n / 4) * n -
  //
  cin >> n;

  ll res = 0;
  ll m = 1000000007;

  if (n > 2 && n % 2 == 0) {
    res = binpow(2, n / 2, m);
  } else if (n > 3) {
    res = 3;
    n -= 3;
    res = (res * binpow(2, n / 2, m)) % m;
  } else {
    res = n;
  }
  cout << res << "\n";

  // Works but too slow.
  /*
  while (n > 3) {
    res = (res * 2) % m;
    n -= 2;
  }
  res = res * n % m;
  */
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
