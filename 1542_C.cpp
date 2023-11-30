#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll ans = 0;
  ll n;

  cin >> n;

  // 1. Add the odd numbers, they have 2 as x.
  ans += (n + n % 2);

  // Now we only have even numbers.

  // 2. Add multiples of 6
  ll multiples_of_6 = n / 6;
  ans += ((n / 2) - multiples_of_6) * 3;

  // Now for odd multiples of 6
  ll odd_multiples_of_6 = multiples_of_6 / 2 + multiples_of_6 % 2;
  ans += 4 * odd_multiples_of_6;

  // 2, 2*3, 6*2, 12*5, 60*7
  // 2*2*3*5*7

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;

  while (t--)
    solution();

  return 0;
}
