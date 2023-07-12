#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll k, x;

  cin >> k >> x;

  if (x / k >= k) {
    cout << 2 * k - 1 << "\n";
    return;
  }

  ll ans = 0;
  if (x / k <= (k + 1) / 2) {
    // find n such that 2*x = (n^2 + n), then take ans = ceil(n)
    double n = -0.5 + sqrt(1 / 4 + 2 * x);
    ans = ceil(n);
  } else {
    // similar procedure but first remove k(k+1)/2
    // find n such that n*k - n(n+1)/2 = 2x - k(k+1)
    //
    // => n = (2*k-1)/2 - sqrt(((2*k-1)/2)^2 - 2*x + k(k+1))
    //
    // then take ans = k + ceil(n)
    double n_factor = (double)(2 * k - 1) / 2;
    double n = n_factor - sqrt(n_factor * n_factor - 2 * x + k * (k + 1));
    ans = ceil(n) + k;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
