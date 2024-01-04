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
  int n;

  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll tot = 0;
  int odds = 0;
  for (int i = 0; i < n; i++) {
    tot += a[i];

    if (a[i] & 1) {
      odds++;
    }

    int odd_copy = odds;

    int sub = 0;

    if (i > 0) {
      sub = odds / 3 + (odds % 3) % 2;
    }

    string padd = (i == n - 1) ? "" : " ";

    cout << tot - sub << padd;
  }
  cout << "\n";
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
