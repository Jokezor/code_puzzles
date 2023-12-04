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
  ll optimal_days = ((n - 8) / 14) + (int)(n >= 8);

  while (optimal_days > 0 && p > 0) {
    ans++;
    p -= (2 * t + l);
    optimal_days--;
  }

  bool taken_task = false;
  while (p > 0) {
    if (n < 8 && !taken_task) {
      p -= t;
      taken_task = true;
    }
    p -= l;
    ans++;
  }

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
