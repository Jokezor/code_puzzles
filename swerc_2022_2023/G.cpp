#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  // All critics should taste the same number of white wines
  // All critics should taste at least n wines
  // No critics should taste the exactly same wines
  //
  // Find x such that the valid intervals are met and
  // each critic taste exactly x white wines

  // Actually, if we find the maximum x for any n length interval, then that
  // interval can be repeated n-1 times. For example, if you were to find an
  // interval of wines not including another W it's valid. If you found another
  // W > x, then the length is greater than n. Decrease the wines added until
  // you have x. This can be done since there are 2n - 1 bottles of wine.

  vector<ll> prefix_sum(2 * n, 0);

  // Get the number of whites
  for (int i = 0; i < 2 * n - 1; i++) {
    prefix_sum[i + 1] = prefix_sum[i] + (s[i] == 'W');
  }

  ll x = 0;
  for (int i = 0; i < n; i++) {
    x = max(x, prefix_sum[i + n] - prefix_sum[i]);
  }

  cout << x << endl;
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
