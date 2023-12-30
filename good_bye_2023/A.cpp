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

void solution() {
  // Solve it
  ll n, k;
  ll a = 1;

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    a *= b;
  }

  if (2023 % a) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (int i = 0; i < k - 1; ++i) {
    cout << "1 ";
  }
  cout << 2023LL / a << "\n";
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
