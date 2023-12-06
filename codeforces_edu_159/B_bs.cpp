#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MAX = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

void solution() {
  ll n, p, l, t;
  cin >> n >> p >> l >> t;

  ll ans = 0;

  // Take optimal multiples
  ll tasks = (ll)((n + 6) / 7);

  auto calc = [&](ll k) -> ll { return k * l + min(2LL * k, tasks) * t; };

  ll left = 0L;
  ll right = n;

  while (right - left > 1) {
    ll mid = (right + left) / 2;
    if (calc(mid) >= p) {
      right = mid;
    } else {
      left = mid;
    }
  }
  ans = right;

  cout << n - ans << "\n";
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
