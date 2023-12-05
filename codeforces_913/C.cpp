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
  int n;

  cin >> n;
  string s;
  cin >> s;

  vector<int> char_counter(26, 0);

  for (int i = 0; i < n; i++) {
    char_counter[s[i] - 'a']++;
  }

  ll max_char = MAX(char_counter);
  if (2 * max_char > n) {
    cout << 2 * max_char - n << "\n";
  } else {
    cout << n % 2 << "\n";
  }
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
