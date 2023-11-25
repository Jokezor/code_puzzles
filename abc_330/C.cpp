#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll closestDiff(ll D) {
  ll min_diff = D;
  ll x = 0, y = sqrt(D);

  while (x <= y) {
    ll cur = x * x + y * y;
    min_diff = min(min_diff, abs(cur - D));

    if (cur < D)
      x++;
    else if (cur > D)
      y--;
    else
      break; // cur == D, found the optimal solution
  }
  return min_diff;
}

void solution() {
  ll D;
  cin >> D;

  cout << closestDiff(D) << "\n";
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
