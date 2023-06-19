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
  // Zn + Zn-1 - 2 Zn-2
  // = Sn + Sn-1 + Pn + Pn-1 - 2*Sn-2 - 2*Pn-2
  // (Sn + Sn-1) - 2*Sn-2 = (n^k + 2*(n-1)^k)
  // (Pn + Pn-1) - 2*Pn-2 = (n^n + 2*(n-1)^(n-1))
  ll n, k;

  ll m = 10000007;

  while (cin >> n >> k) {
    if (n == 0 && k == 0) {
      break;
    }
    ll res;
    res = (binpow(n, k, m) + 2 * binpow(n - 1, k, m)) % m;
    res = (res + binpow(n, n, m)) % m;
    res = (res + 2 * binpow(n - 1, n - 1, m)) % m;
    cout << res << "\n";
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
