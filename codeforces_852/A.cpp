#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  ll a = 0, b = 0, n = 0, m = 0, result = 0;

  cin >> a >> b;
  cin >> n >> m;

  // Take out how many groups of m+1 potatoes there are
  ll promotions_available = (n / (m + 1));

  // All the potatoes outside of the group
  ll singles = n % (m + 1);

  // Add the minimum cost to buy the whole group of potatoes
  // It costs m with a but m+1 for b due to the promotion.
  result = min(m * a, (m + 1) * b) * promotions_available;
  // Finally, add the cost of the singles.
  result += min(singles * a, singles * b);

  cout << result << "\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
