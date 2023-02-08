#include <bits/stdc++.h>
#define ll long long
#define startt                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);
using namespace std;

void solution() {
  ll n, c;
  cin >> n >> c;
  vector<pair<ll, ll>> a;

  // First make a vector of pairs.
  // The first value is the minimum cost, either from left or right.
  // The second value is the cost from the left.
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.push_back({x + min(i + 1, n - i), x + i + 1});
  }
  // Sort the array of costs.
  sort(a.begin(), a.end());

  // Make a prefix_sum
  vector<ll> prefix_sum;
  prefix_sum.push_back(0);

  // It will hold the cost for getting to the teleport
  // While considering the most optimal.
  for (ll i = 0; i < n; i++) {
    prefix_sum.push_back(prefix_sum.back() + a[i].first);
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    // Take the teleport from the left since we start at 0.
    ll new_c = c - a[i].second;
    ll l = 0, r = n;
    ll mx = 0;

    // Binary search for what the total number of teleports is if
    // we took the current teleport i.
    while (l <= r) {
      // equivalent to l + r / 2
      ll mid = (l + r) >> 1;
      // Calculate price
      ll price = prefix_sum[mid];
      ll now = mid + 1;

      // This means that we are further away than the current teleport.
      // We can thus take the most optimal path, since we can use both
      // left and right.
      if (mid > i) {
        price -= a[i].first;
        now--;
      }
      // If the current cost was lower than what coins we have,
      // Continue checking for more expensive teleport.
      // Otherwise, consider cheaper ones.
      if (price <= new_c) {
        mx = max(now, mx);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    // Take the answer to the new optimal.
    // mx is actually taken from the index.
    ans = max(ans, mx);
  }
  cout << ans << endl;
}

int32_t main() {
  startt int t;
  cin >> t;
  while (t--)
    solution();
}
