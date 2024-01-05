#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

using namespace std;

ll MAX_VAL = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

void print(auto &&r) {
  std::ranges::for_each(r, [](auto &&i) { std::cout << i << ' '; });
}

void solution() {
  // Solve it
  int n, k, d;

  cin >> n >> k >> d;

  vector<int> a(n);
  vector<int> v(k);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++) {
    cin >> v[i];
  }

  ll ans = 0;

  for (int i = 0; i < d && i <= 2 * n; ++i) {
    ll cur = 0;
    for (int j = 0; j < n; j++) {
      cur += (a[j] == j + 1);
    }
    cur += (d - i - 1) / 2;

    ans = max(cur, ans);
    for (int j = 0; j < v[i % k]; j++) {
      a[j]++;
    }
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
