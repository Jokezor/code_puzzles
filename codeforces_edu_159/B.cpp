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

  ll optimal_days = tasks / 2;
  ll optimal_day_value = 2 * t + l;

  ll needed_days = (ll)ceil((double)p / optimal_day_value);

  // cout << optimal_days << " " << needed_days << "\n";

  // Want to find min x s.t x*y >= p
  // ceil((double)p/y) gives x.
  // So we take min(optimal_days, ceil((double)p/y))
  ll optimal_days_used = min(optimal_days, needed_days);

  ans += optimal_days_used;
  p -= optimal_days_used * optimal_day_value;

  // cout << ans << " " << p << "\n";

  if (p > 0) {
    p -= (tasks % 2) * t;
    p -= l;
    ans += 1;
  }

  // cout << ans << " " << p << "\n";

  ans += max(0LL, (ll)ceil((double)p / l));

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
