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
  // Smallest number we can construct with
  // [0, a] or [a, 0]
  // We want an odd number of negative numbers.
  // Otherwise we choose 0.
  // For example if we have even negative numbers, choose first and set to 0.
  // (Same with 0) If we have odd negative numbers, do nothing.
  int n;
  cin >> n;

  int num_negative = 0;
  bool has_0 = false;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a < 0) {
      num_negative++;
    } else if (a == 0) {
      has_0 = true;
    }
  }

  if (has_0) {
    cout << "0\n";
    return;
  }

  // Odd number of negative numbers
  if (num_negative & 1) {
    cout << "0\n";
    return;
  }

  cout << 1 << "\n";
  cout << "1 0\n";
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
